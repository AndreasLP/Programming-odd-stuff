import random, sys
data = []
for i in range(1024):
    data.append((random.randint(0,255)))
data = bytes(data)    
if len(sys.argv) == 2:
    filename = 'randfile'+sys.argv[1]+'.txt'
elif len(sys.argv) == 3:
    filename = sys.argv[2] + '/randfile' + sys.argv[1] + '.txt'
else:
    filename = 'randfile.txt'

with open(filename, 'wb') as f:
    f.write(data)
    
