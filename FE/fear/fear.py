#!/usr/bin/env python2
# coding: utf-8

MAGIC   = 'FEAr'
VERSION = 1

import os
import stat
import sys
import errno
import struct
import zlib
import hashlib

from collections import defaultdict
from heapq import heappush, heappop, heapify

def die(msg = '', status = 1):
    if msg:
        print >>sys.stderr, msg
    sys.exit(status)

VERBOSE = False
def log(msg):
    if VERBOSE:
        print >>sys.stderr, msg

def warn(msg):
    print >>sys.stderr, '\x1b[31m%s\x1b[m' % msg

def crc32(data):
    return zlib.crc32(data) & 0xffffffff

def split(data, n):
    out = [''] * n
    sz = (len(data) + n - 1) // n
    i = 0
    for j in xrange(n):
        out[j] = data[i : i + sz]
        i += sz

    # PKCS#5 padding to make all pieces same size
    for j in xrange(n):
        p = sz - len(out[j]) + 1
        out[j] += chr(p) * p

    return out

def ecc(pieces, n):
    ###
    ### Error correction using Reed-Solomon codes
    ###

    ##
    ## Field operations for F_{2^n}
    ## Elements are represented as polynomials over bits
    ##

    # Conway polynomials for F_{2^n} for n = 1..32.
    #  http://www.math.rwth-aachen.de/~Frank.Luebeck/data/ConwayPol/CP2.html
    Gs = {
        1: 3,
        2: 7,
        3: 11,
        4: 19,
        5: 37,
        6: 91,
        7: 131,
        8: 285,
        9: 529,
        10: 1135,
        11: 2053,
        12: 4331,
        13: 8219,
        14: 16553,
        15: 32821,
        16: 65581,
        17: 131081,
        18: 267267,
        19: 524327,
        20: 1050355,
        21: 2097253,
        22: 4202337,
        23: 8388641,
        24: 16901801,
        25: 33554757,
        26: 67126739,
        27: 134223533,
        28: 268443877,
        29: 536870917,
        30: 1073948847,
        31: 2147483657,
        32: 4295000729,
        }

    # Field order is 2**N
    N = 8

    # For debugging
    def str_poly(p):
        if p == 0:
            return '0'
        d = deg(p)
        sups = {'0': '⁰',
                '1': '¹',
                '2': '²',
                '3': '³',
                '4': '⁴',
                '5': '⁵',
                '6': '⁶',
                '7': '⁷',
                '8': '⁸',
                '9': '⁹',
                }
        def sup(n):
            return ''.join(sups[d] for d in str(n))
        out = []
        for i in range(d, 0, -1):
            if p & (1 << i):
                out.append('x' + sup(i))
        if p & 1:
            out.append('1')
        return ' + '.join(out)

    # Addition and subtractions is the same operation
    def add(x, y):
        return x ^ y
    sub = add

    # Multiply
    def mul(x, y):
        z = 0
        if y < x:
            x, y = y, x
        while x:
            if x & 1:
                z ^= y
            y <<= 1
            x >>= 1
        return polydiv(z, Gs[N])[1]

    # Polynomial degree
    def deg(x):
        d = -1
        while x:
            d += 1
            x >>= 1
        return d

    # Polynomial long division
    #  https://en.wikipedia.org/wiki/Polynomial_long_division
    def polydiv(x, y):
        if not y:
            raise ZeroDivisionError
        dx = deg(x)
        dy = deg(y)
        # y doesn't divide x
        if dy > dx:
            return 0, x
        z = 0
        # Align the leading terms
        y <<= dx - dy
        # For each term at least as large as y's leading term
        i = dx
        while i >= dy:
            z <<= 1
            # Subtract y
            if x & 1 << i:
                z |= 1
                x = sub(x, y)
            y >>= 1
            # Next term
            i -= 1
        return z, x

    # Extended Euclidean algorithm
    #  https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
    def egcd(a, b):
        if b == 0:
            return 1, 0
        q, r = polydiv(a, b)
        x, y = egcd(b, r)
        return y, sub(x, mul(q, y))

    # Inverse
    def inv(x):
        # By construction of Gs[N] we have gcd(x, Gs[N]) == 1
        return egcd(x, Gs[N])[0]

    # Division
    def div(x, y):
        return mul(x, inv(y))

    ##
    ## Matrix operations on matrices over F_{2^N}
    ##

    # Matrix dimension as (rows, columns)
    def dim(A):
        return len(A), len(A[0])

    def transpose(A):
        h, w = dim(A)
        return [[A[j][i] for j in xrange(h)] for i in xrange(w)]

    # Multiply by a vector, i.e returns t = A x v
    def mul_vec(A, v):
        return [reduce(add, map(mul, row, v)) for row in A]

    # Gauss-Jordan elimination
    #  https://en.wikipedia.org/wiki/Gaussian_elimination
    # In-place
    def gauss_jordan(A):
        i, j = 0, 0
        m, n = dim(A)
        for k in range(min(m, n)):
            # Find a row with pivot in column k
            for i in range(k, m):
                if A[i][k]:
                    # Found it
                    break
            else:
                # No row with pivot in column k, next please
                raise ValueError('Matrix is singular')
            # Swap rows
            A[i], A[k] = A[k], A[i]

            # Divide row k by pivot
            for j in range(k + 1, n):
                A[k][j] = div(A[k][j], A[k][k])
            # Pivot is now one
            A[k][k] = 1

            # Eliminate all other column k pivots
            for i in range(m):
                if i == k:
                    continue
                # Subtract (row i pivot) x (row k) from row i
                for j in range(k + 1, n):
                    A[i][j] = sub(A[i][j], mul(A[i][k], A[k][j]))
                # (Former) pivot now zero
                A[i][k] = 0
        return A

    # Find the inverse of a matrix using Gauss-Jordan elimination; see above
    def inverse(A):
        n, m = dim(A)
        if n != m:
            raise ValueError('Not a square matrix')
        # Append identity matrix
        for i, row in enumerate(A):
            row += [0] * n
            row[n + i] = 1
        # Find inverse
        gauss_jordan(A)
        # Discard now-identity matrix
        for row in A:
            row[:n] = []
        return A

    # For debugging
    def str_matrix(A):
        align = max(max(len(`cell`) for cell in row) for row in A)
        h, w = dim(A)
        pad = w * (align + 1) + 1
        out  = '.'
        hdr = '< %d x %d >' % (w, h)
        out += '-' * ((pad - len(hdr)) // 2)
        out += hdr
        out += '-' * ((pad - len(hdr) + 1) // 2)
        out += '.\n'
        for row in A:
            out += '| '
            for cell in row:
                out += `cell`.rjust(align) + ' '
            out += '|\n'
        out += '\''
        out += '-' * pad
        out += '\''
        return out

    ##
    ## Reed-Solomon encoding
    ##  https://en.wikipedia.org/wiki/Reed%E2%80%93Solomon_error_correction
    ##  http://web.mit.edu/~emin/Desktop/ref_to_emin/www.old/source_code/py_ecc
    ##

    # Generate encoder matrix for an RS code with block length n and message
    # length k
    def encoder_matrix(n, k, systematic=True):
        A = [[1] * k for _ in xrange(n)]
        for i in xrange(n):
            t = 1
            for j in xrange(k):
                A[i][j] = t
                t = mul(t, i)
        if systematic:
            A = transpose(A)
            A = gauss_jordan(A)
            A = transpose(A)
        return A

    # Given an encoder matrix, encoding is just vector multiplication
    def encode(A, msg):
        return mul_vec(A, msg)

    # Given a decoder matrix, decoding is the same
    decode = encode

    # Given n lists of byte values add k lists of redundancy.  The original
    # lists can be reconstructed from any n of the (n + k) new lists.  All the
    # lists must contain the same number of bytes.
    k = len(pieces)
    A = encoder_matrix(n, k)
    out = []
    for v in zip(*pieces):
        t = encode(A, map(ord, v))
        out.append(map(chr, t))
    x = [''.join(p) for p in zip(*out)]
    return [''.join(p) for p in zip(*out)]

def noise(data):
    prev = os.urandom(20)
    out = prev
    for i in xrange(0, len(data), 20):
        this = data[i : i + 20]
        out += ''.join(chr(ord(a) ^ ord(b)) for a, b in zip(prev, this))
        prev = this
    return out

def encrypt_coffee(data, password):
    # PKCS#5 padding
    padding = -len(data) % 8
    if not padding:
        padding = 8
    data += chr(padding) * padding

    key = struct.unpack('!IIII', hashlib.sha1(password).digest()[:16])

    out = ''
    for i in xrange(0, len(data), 8):
        msg = list(struct.unpack('!II', data[i : i + 8]))
        s = 0

        for _ in xrange(32):
            s = (s + 0x9e3779b9) & 0xffffffff
            msg[0] = (msg[0] + \
                      (((msg[1] << 4) + key[0]) ^ \
                       ( msg[1] +            s) ^ \
                       ((msg[1] >> 5) + key[2])
                       )
                      ) & 0xffffffff
            msg[1] = (msg[1] + \
                      (((msg[0] << 4) + key[1]) ^ \
                       ( msg[0]       + s     ) ^ \
                       ((msg[0] >> 5) + key[3])
                       )
                      ) & 0xffffffff

        out += struct.pack('!II', *msg)

    return out

def encrypt_benc(data, password):
    S = map(ord, hashlib.sha256(password).digest())

    out = ''
    for c in data:
        out += chr(ord(c) ^ S.pop(0))
        S.append(S[7] ^ S[9] ^ S[13])

    return out

def encrypt_fcrypt(data, password):
    def rot(x, n):
        return ((x << n) | x >> (32 - n)) & 0xffffffff
    def f(x):
        return (0xb819 - (0x47e6 ^ rot(x, 17))) & 0xffffffff

    # PKCS#5 padding
    padding = -len(data) % 8
    if not padding:
        padding = 8
    data += chr(padding) * padding

    IV  = struct.unpack('II', os.urandom(8))
    key = struct.unpack('!II', hashlib.sha1(password).digest()[:8])

    # Write IV
    out = struct.pack('!II', *IV)

    for i in xrange(0, len(data), 8):
        msg = list(struct.unpack('!II', data[i : i + 8]))

        # Add IV
        msg[0] ^= IV[0]
        msg[1] ^= IV[1]

        # Add key
        msg[0] ^= key[0]
        msg[1] ^= key[1]

        # Mix
        msg[0] ^= f(msg[1])
        msg[1] ^= f(msg[0])

        # Add key
        msg[0] ^= f(key[0] ^ IV[0])
        msg[1] ^= f(key[1] ^ IV[1])

        # Output
        out += struct.pack('!II', *msg)

        # Update IV
        IV = msg

    return out

def bits(x, n):
    out = []
    for _ in xrange(n):
        out.append(x & 1)
        x >>= 1
    if x:
        die('Too few bits')
    return out

def vlq(x):
    octets = []
    while True:
        x, y = divmod(x, 0x80)
        octets.append(bits(y, 7))
        if not x:
            break
    out = []
    for o in reversed(octets[1:]):
        out += o + [1]
    out += octets[0] + [0]
    return out

def hmc(data):
    maxsym = max(data)
    size = 1
    while 2**size <= maxsym:
        size += 1

    freqs = defaultdict(int)
    for sym in data:
        freqs[sym] += 1

    heap = [(wt, sym) for sym, wt in freqs.items()]
    heapify(heap)

    while len(heap) > 1:
        ka, va = heappop(heap)
        kb, vb = heappop(heap)
        kc = ka + kb
        vc = (va, vb)
        heappush(heap, (kc, vc))

    root = heap[0][1]
    codebook = {}

    def encode(x, p=[]):
        if isinstance(x, tuple):
            return [0] + encode(x[0], p + [0]) + encode(x[1], p + [1])
        codebook[x] = p
        return [1] + bits(x, size)

    bs = vlq(size) + encode(root)

    if len(codebook) == 1:
        bs += vlq(len(data))
    else:
        for sym in data:
            bs += codebook[sym]

    padding = -len(bs)%8
    bs = vlq(padding) + bs + [0] * padding

    out = ''
    for i in xrange(0, len(bs), 8):
        n = 0
        for j in xrange(8):
            b = bs[i + 7 - j]
            n <<= 1
            n |= b
        out += chr(n)
    return out

def compress_zlib(data):
    return zlib.compress(data)

def compress_hmc(data):
    return hmc(map(ord, data))

def compress_bpk(data):
    out = ""
    codebook = [(0, 0, "")] * 255
    i = 0
    def score ((j, n, c)):
        return (j - i) * 2 + n * 4 + len(c) * 7
    def insert (e):
        for j in range(255):
            if score(e) > score(codebook[j]):
                codebook.insert(j, e)
                break
    while i < len(data):
        t = data[i:]
        k = 255 # entry
        l = 0   # length
        for j in range(255):
            (_, _, c) = codebook[j]
            if t.startswith(c) and len(c) > l and len(c) + i < len(data):
                k = j
                l = len(c)
        out += chr(k) + t[l]

        if k < 255: # "Upgrade" entry in codebook
            (_, n, c) = codebook[k]
            del codebook[k]
            insert((i, n + 1, c))

        insert((i, 1, t[:l + 1])) # insert this entry
        codebook.pop() # remove entry with lowest score

        i += l + 1
    return out

def compress_qed(data):
    if not data:
        return ''

    c = data[0]
    Z = 0x100
    G = [[float('inf'), [c]]]

    def p1((a, b)):
        seen = False
        for i, r in enumerate(G):
            c = r[1][0]
            for d in r[1][1:]:
                if (a, b) == (c, d):
                    if seen:
                        return True
                    seen = True
                c = d
        return False

    def p2():
        for i, (rc, _) in enumerate(G):
            if rc < 2:
                yield i

    def isterminal(x):
        return isinstance(x, str)

    def ref(xs, n):
        for x in xs:
            if not isterminal(x):
                G[x][0] += n

    def find(link):
        for i, (_, s) in enumerate(G):
            if tuple(s) == link:
                return i

        G.append([0, list(link)])
        ref(link, 1)

        return len(G) - 1

    def use(i):
        links = []
        rc, s1 = G[i]
        for _, s2 in G:
            if s1 == s2:
                continue
            j = 0
            while j <= len(s2) - len(s1):
                if s2[j:j + len(s1)] == s1:
                    ref(s2[j:j + len(s1)], -1)
                    s2[j:j + len(s1)] = [i]
                    rc += 1
                    if j:
                        links.append((s2[j-1], s2[j]))
                j += 1
        G[i][0] = rc
        return links

    def rem(i):
        links = []
        _, s1 = G.pop(i)
        for _, s2 in G:
            j = 0
            while j < len(s2):
                if s2[j] == i:
                    s2[j:j+1] = s1
                    if j:
                        links.append((s2[j-1], s2[j]))
                    j += len(s1)
                    continue
                elif not isterminal(s2[j]) and s2[j] > i:
                    s2[j] -= 1
                j += 1
        return links

    # This algorithm is rather slow; better log progress
    progress = ''
    for i, c in enumerate(data[1:]):
        progress_ = '%d%%' % (i * 100 // len(data))
        if progress != progress_:
            progress = progress_
            log(progress)
        G[0][1].append(c)
        links = [tuple(G[0][1][-2:])]
        while links:
            link = links.pop()
            if p1(link):
                rule = find(link)
                links += use(rule)
            for rule in p2():
                links += rem(rule)

    data = []
    for n, (_, xs) in enumerate(G):
        for x in xs:
            if isterminal(x):
                x = ord(x)
            else:
                x += Z
            data.append(x)
        data.append(Z)

    data.pop()

    return hmc(data)

def pack(path):
    path = os.path.normpath(path)
    Q = [path]
    objs = []
    while Q:
        path = Q.pop(0)

        st = os.stat(os.path.realpath(path))
        mode  = st.st_mode
        islnk = False
        isdir = False
        data  = ''
        link  = ''

        if stat.S_ISDIR(mode):
            isdir = True
            log('Dir: %s/' % path)
            for entry in os.listdir(path):
                Q.append(os.path.join(path, entry))

        elif os.path.islink(path):
            islnk = True
            link = os.readlink(path)
            log('Link: %s -> %s' % (path, link))
            if len(link) > 100:
                die('Path too long: %s' % link)

        elif stat.S_ISREG(mode):
            log('File: %s' % path)
            try:
                data = file(path, 'rb').read()
            except IOError as e:
                if e.errno != errno.EPERM:
                    raise
                die('Cannot read file: %s: Permission denied' % path)

        def number(x, sz):
            return oct(x)[1-sz:].rjust(sz-1, '0') + '\0'

        if isdir:
            size = 0
            path += '/'

        if len(path) > 100:
            die('Path too long: %s' % path)

        name  = path.ljust(100, '\0')
        mode  = number(stat.S_IMODE(mode), 8)
        uid   = number(st.st_uid, 8)
        gid   = number(st.st_gid, 8)
        size  = number(len(data), 12)
        mtime = number(int(st.st_mtime), 12)
        islnk = '2' if islnk else '0'
        link  = link.ljust(100, '\0')
        cksum = ' ' * 8

        hdr = ''.join((name, mode, uid, gid, size, mtime, cksum, islnk, link))
        cksum = number(sum(map(ord, hdr)), 7) + ' '
        hdr = (hdr[:148] + cksum + hdr[156:]).ljust(512, '\0')

        obj = hdr + data

        objs.append(obj)

    return ''.join(objs)

if __name__ == '__main__':
    import argparse
    p = argparse.ArgumentParser(
        description = 'FEAr',
    )

    p.add_argument(
        'src',
        metavar = '<path>',
        help = 'Source file or directory.',
    )

    p.add_argument(
        '--force', '-f',
        action = 'store_true',
        help = 'Overwrite when extracting.',
    )

    p.add_argument(
        '--outdir', '-o',
        metavar = '<path>',
        default = '.',
        help = 'Extract relative to <path>.  (default: .)',
    )

    p.add_argument(
        '--extract', '-x',
        metavar = '<path>',
        help = 'Extract archive.',
    )

    p.add_argument(
        '--create', '-c',
        metavar = '<path>',
        help = 'Create a new archive.',
    )

    p.add_argument(
        '--compress', '-z',
        nargs = '?',
        choices = ('zlib', 'hmc', 'bpk', 'qed'),
        help = 'Compress archive.  Optionally choose algorithm.  (default: '
        'zlib)',
        default = False,
    )

    p.add_argument(
        '--encrypt', '-e',
        nargs = '?',
        choices = ('coffee', 'benc', 'fcrypt'),
        help = 'Encrypt archive.  Optionally choose an algorithm.  (default: '
        'coffee)',
        default = False,
    )

    p.add_argument(
        '--noise',
        action = 'store_true',
        help = 'Make archive look like random data.',
    )

    p.add_argument(
        '--split',
        type = int,
        metavar = '<num>',
        help = 'Split archive into <num> files plus one file for metadata.',
    )


    p.add_argument(
        '--ecc',
        type = int,
        help = 'Use error correcting codes to protect against some data '
        'corruption.',
    )

    p.add_argument(
        '--password',
        help = 'Password used for encryption/decryption.',
    )

    p.add_argument(
        '--verbose', '-v',
        action = 'store_true',
        help = 'Enable verbose output.',
    )

    args = p.parse_args()
    if args.verbose:
        VERBOSE = True

    if args.extract:
        die('Not implemented yet')

    elif args.create:
        dst = args.create
        info = [VERSION] + [0] * 11
        data = pack(args.src)
        pieces = []

        if args.compress != False:
            args.compress = args.compress or 'zlib'
            log('Compression: %s' % args.compress)
            n, f = {'zlib'   : (1, compress_zlib),
                    'hmc'    : (2, compress_hmc),
                    'bpk'    : (3, compress_bpk),
                    'qed'    : (4, compress_qed),
                    }[args.compress]
            info[1] = n
            data = f(data)

        if args.encrypt != False:
            if not args.password:
                args.password = raw_input('Password: ')
            args.encrypt = args.encrypt or 'coffee'
            log('Encryption: %s' % args.compress)
            n, f = {'coffee': (1, encrypt_coffee),
                    'benc'   : (2, encrypt_benc),
                    'fcrypt' : (3, encrypt_fcrypt),
                    }[args.encrypt]
            info[2] = n
            data = f(data, args.password)

        if args.noise:
            log('Noise: Yes')
            info[3] = 1
            data = noise(data)

        if args.split:
            # PKCS#5 padding limits number of pieces to 255
            if args.split > 255:
                die('Can split into at most 255 pieces')
            log('Split: %d pieces' % args.split)
            info[4] = args.split << 1 | 1
            pieces = split(data, args.split)
            data = ''

            if args.ecc:
                if args.ecc > 127:
                    die('Can add at most 127 pieces of redundancy')
                log('Error correction: %d extra pieces (~%d%% redundancy)' % \
                    (args.ecc, 100 * args.ecc / (args.split + args.ecc)))
                info[5] = args.ecc << 1 | 1
                pieces = ecc(pieces, args.split + args.ecc)

        elif args.ecc:
            die('You must also specify --split to use --ecc')

        size = len(data) + 24
        hdr = MAGIC + ''.join(map(chr, info)) + struct.pack('!I', size)
        crc = crc32(hdr + data)
        hdr += struct.pack('!I', crc)

        log('')
        log('File: %s' % dst)
        log('Size: %dB' % size)
        log('CRC : 0x%08x' % crc)

        if pieces:
            file(dst, 'wb').write(hdr)
            for i, piece in enumerate(pieces, 1):
                size = len(piece) + 8
                crc = crc32(piece)
                path = '%s.%d' % (dst, i)
                log('')
                log('File: %s' % path)
                log('Size: %dB' % size)
                log('CRC : 0x%08x' % crc)
                phdr = struct.pack('!II', size, crc)
                file(path, 'wb').write(phdr + piece)
        else:
            file(dst, 'wb').write(hdr + data)
    else:
        die('Must give --create or --extract')
