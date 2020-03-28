import itertools as it
import sys
from cipher import *

if len(sys.argv) != 2:
    filename = input()
else:
    filename = sys.argv[1]

f = open(filename, 'rb')
cnt = f.read()
f.close()
psw_strength = cnt[0:3]
cnt = cnt[3:]
magic_cnt = cnt[0:4]
pswchars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"


if psw_strength == "HIG":
    min_strength = 7
    max_strength = 20
    print("HIG password")
elif psw_strength == "MED":
    min_strength = 5
    max_strength = 6
    print("MED password")
else:
    min_strength = 1
    max_strength = 4
    print("LOW password")

version = 2

b = bytearray([i for i in range(256)])
psw_fnd = False
count = 0
if version == 2:
    if not psw_fnd:
        for psw_cand in range(16777215 + 1):
            psw_cand = psw_cand << 3
            count += 1
            if count % 10000 == 0:
                print(count)
            magic_dec = decrypt(magic_cnt, psw_cand, crypt='dec')
            if magic_dec == MAGIC:
                psw_fnd = True
                print 'Password %s' % psw_cand
                break
else:
    for length in range(min_strength, max_strength + 1):
        if not psw_fnd:
            print 'Length %s' % length
            for per in it.permutations(pswchars, length):
                per = ''.join(per)
                magic_dec = decrypt(magic_cnt, per)
                if magic_dec == MAGIC:
                    psw_fnd = True
                    print 'Password %s' % per
                    break
