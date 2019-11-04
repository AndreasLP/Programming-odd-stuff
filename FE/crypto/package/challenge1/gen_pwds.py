"""
This file produces a sequence of passwords and prints them out. One of
these passwords was used to encrypt file.enc with psw_enc.py.

The decryption of file.enc is a Python script.

Provide source code to decrypt file.enc.
"""

import sys
import psw_enc


class PWDGen:
    def __init__(self, init = '\00'*16):
        self.mod = psw_enc.CryptoModule(init)
        self.words = ["foo", "bar", "ba", "er", "de", "dam", "food", "slam"]
        
    def getNext(self):
        pwd = self.words[(self.mod.getNext()) % 8]
        while (self.mod.getNext()) % 4 != 0:
            pwd += self.words[(self.mod.getNext()) % 8]
        return pwd

if __name__ == "__main__":
    pwdGen = PWDGen()

    for i in range(2048):
        print(pwdGen.getNext())
