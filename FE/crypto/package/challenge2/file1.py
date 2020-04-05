import sys
from substitution import *

ciphers = [Substitution({'A': 'I', 'C': 'S', 'B': 'J', 'E': 'K', 'D': 'C', 'G': 'H', 'F': 'A', 'I': 'F', 'H': 'U',
                         'K': 'T', 'J': 'V', 'M': 'R', 'L': 'P', 'O': 'Y', 'N': 'Z', 'Q': 'M', 'P': 'B', 'S': 'W',
                         'R': 'X', 'U': 'G', 'T': 'O', 'W': 'D', 'V': 'E', 'Y': 'N', 'X': 'L', 'Z': 'Q'}),
           Substitution({'A': 'T', 'C': 'H', 'B': 'Z', 'E': 'C', 'D': 'U', 'G': 'I', 'F': 'V', 'I': 'R', 'H': 'Y',
                         'K': 'E', 'J': 'P', 'M': 'X', 'L': 'J', 'O': 'F', 'N': 'L', 'Q': 'K', 'P': 'S', 'S': 'B',
                         'R': 'D', 'U': 'O', 'T': 'Q', 'W': 'W', 'V': 'M', 'Y': 'N', 'X': 'A', 'Z': 'G'}),
           Substitution({'A': 'L', 'C': 'E', 'B': 'V', 'E': 'M', 'D': 'U', 'G': 'G', 'F': 'C', 'I': 'Z', 'H': 'P',
                         'K': 'D', 'J': 'Y', 'M': 'T', 'L': 'Q', 'O': 'J', 'N': 'F', 'Q': 'X', 'P': 'K', 'S': 'S',
                         'R': 'O', 'U': 'I', 'T': 'W', 'W': 'R', 'V': 'H', 'Y': 'B', 'X': 'A', 'Z': 'N'}),
           Substitution({'A': 'R', 'C': 'F', 'B': 'Z', 'E': 'T', 'D': 'U', 'G': 'L', 'F': 'Y', 'I': 'W', 'H': 'I',
                         'K': 'E', 'J': 'K', 'M': 'G', 'L': 'D', 'O': 'V', 'N': 'N', 'Q': 'S', 'P': 'H', 'S': 'M',
                         'R': 'Q', 'U': 'C', 'T': 'X', 'W': 'A', 'V': 'B', 'Y': 'P', 'X': 'J', 'Z': 'O'}),
           Substitution({'A': 'B', 'C': 'F', 'B': 'P', 'E': 'H', 'D': 'T', 'G': 'A', 'F': 'Z', 'I': 'X', 'H': 'W',
                         'K': 'I', 'J': 'V', 'M': 'L', 'L': 'M', 'O': 'Q', 'N': 'S', 'Q': 'J', 'P': 'N', 'S': 'O',
                         'R': 'C', 'U': 'E', 'T': 'G', 'W': 'R', 'V': 'K', 'Y': 'Y', 'X': 'D', 'Z': 'U'}),
           Substitution({'A': 'M', 'C': 'K', 'B': 'C', 'E': 'V', 'D': 'R', 'G': 'E', 'F': 'W', 'I': 'L', 'H': 'B',
                         'K': 'X', 'J': 'I', 'M': 'Z', 'L': 'O', 'O': 'F', 'N': 'S', 'Q': 'J', 'P': 'D', 'S': 'A',
                         'R': 'Y', 'U': 'Q', 'T': 'G', 'W': 'P', 'V': 'U', 'Y': 'N', 'X': 'H', 'Z': 'T'}),
           Substitution({'A': 'W', 'C': 'R', 'B': 'E', 'E': 'C', 'D': 'X', 'G': 'Q', 'F': 'P', 'I': 'I', 'H': 'J',
                         'K': 'V', 'J': 'S', 'M': 'F', 'L': 'Y', 'O': 'Z', 'N': 'U', 'Q': 'M', 'P': 'T', 'S': 'N',
                         'R': 'D', 'U': 'L', 'T': 'H', 'W': 'A', 'V': 'B', 'Y': 'G', 'X': 'O', 'Z': 'K'}),
           Substitution({'A': 'Y', 'C': 'F', 'B': 'D', 'E': 'X', 'D': 'O', 'G': 'P', 'F': 'R', 'I': 'A', 'H': 'T',
                         'K': 'H', 'J': 'N', 'M': 'E', 'L': 'J', 'O': 'M', 'N': 'B', 'Q': 'G', 'P': 'S', 'S': 'Q',
                         'R': 'K', 'U': 'V', 'T': 'I', 'W': 'Z', 'V': 'C', 'Y': 'L', 'X': 'W', 'Z': 'U'}),
           Substitution({'A': 'Z', 'C': 'N', 'B': 'O', 'E': 'L', 'D': 'K', 'G': 'D', 'F': 'P', 'I': 'X', 'H': 'V',
                         'K': 'Y', 'J': 'F', 'M': 'B', 'L': 'E', 'O': 'G', 'N': 'C', 'Q': 'M', 'P': 'R', 'S': 'H',
                         'R': 'J', 'U': 'Q', 'T': 'T', 'W': 'S', 'V': 'U', 'Y': 'I', 'X': 'A', 'Z': 'W'}),
           Substitution({'A': 'V', 'C': 'H', 'B': 'Q', 'E': 'J', 'D': 'N', 'G': 'R', 'F': 'X', 'I': 'L', 'H': 'E',
                         'K': 'O', 'J': 'D', 'M': 'Y', 'L': 'A', 'O': 'I', 'N': 'K', 'Q': 'U', 'P': 'F', 'S': 'W',
                         'R': 'P', 'U': 'G', 'T': 'Z', 'W': 'C', 'V': 'S', 'Y': 'B', 'X': 'M', 'Z': 'T'})]

if len(sys.argv) != 2:
    print 'python %s "QUOTED SUBSTITUTION MESSAGE"' % sys.argv[0]
    sys.exit(-1)

enc = sys.argv[1]

for cipher in ciphers:
    dec = cipher.reverseSubstitution(enc)
    print dec
