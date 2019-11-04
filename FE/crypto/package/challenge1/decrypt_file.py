import os
import psw_enc

f = open('passwords.txt', 'r')
s = f.readlines()
f.close()
s = [(c[:-1]).encode('utf-8') for c in s]

f = open('file.enc', 'rb')
cnt = f.read()

for password in s:
    out = open('decrypted_files/'+password.decode()+'.txt', 'wb')
    dec = psw_enc.encode(cnt, password)
    dec = dec.encode('utf-8')
    out.write(dec)
    out.close()

