import os

files = os.listdir()
s = [0]*len(files)
tests = [b'import',b'def',b'print',b'append(',b'for ',b'if ']
for i in range(len(files)):
    f = open(files[i], 'rb')
    content = f.read()
    f.close()
    for test in tests:
        s[i] = s[i] + content.count(test)

print(files)
print(s)
