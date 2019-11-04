import os

files = os.listdir('decrypted_files')
s = [0]*len(files)
tests = [b'import',b'def',b'print',b'append(',b'for ',b'if ']
for i in range(len(files)):
    f = open('decrypted_files/'+files[i], 'rb')
    content = f.read()
    f.close()
    for test in tests:
        s[i] = s[i] + content.count(test)
files_sorted = [(x,y) for y,x in sorted(zip(s,files), reverse = True)]
print(files_sorted[0:10])
