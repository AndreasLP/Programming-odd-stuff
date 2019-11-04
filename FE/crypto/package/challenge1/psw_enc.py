import hashlib
import sys

from Crypto.Cipher import AES
from struct import *

class CryptoModule:
    def __init__(self, seed = 1):
        self.state = seed
        self.iterate()
        self.index = -1

    def iterate(self):
        key = hashlib.md5('key').digest()
        self.cipher = AES.new(key, mode=AES.MODE_CBC, IV='\x00'*16)
        self.state = self.cipher.encrypt(self.state)

    def getNext(self):
        self.index += 1
        if self.index == 16:
            self.iterate()
            self.index = 0
            
        return self.state[self.index]

def generateSeed(pwd):
    seed = pwd
    for i in range(256):
        seed = hashlib.md5(seed).digest()
    return seed

def encode(pln, pwd):
    enc = []
    mod = CryptoModule(generateSeed(pwd))
    for c in pln:
        enc.append(ord(c) ^ ord(mod.getNext()))
    return ''.join(chr(c) for c in enc)



if __name__ == "__main__":
    def print_usage():
        print("Encrypts <in-file> with <password> to <out-file>")
        print("Usage:")
        print("python {0} <password> <in-file> <out-file>".format(sys.argv[0]) )
        sys.exit(0)

    if len(sys.argv) != 4:
        print_usage()

    pwd       = sys.argv[1]
    in_file   = sys.argv[2]
    out_file  = sys.argv[3]

    f         = open(in_file, "rb")
    cnt       = f.read()
    f.close()

    enc       = encode(cnt, pwd)
    
    f         = open(out_file, "wb")
    f.write(enc)
    f.close()
