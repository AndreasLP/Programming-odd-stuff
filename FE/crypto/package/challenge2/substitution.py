class Substitution:
    def __init__(self, substitution):
        self.substitution = substitution
        self.reverse      = {}
        for k in self.substitution:
            self.reverse[self.substitution[k]] = k

    def makeSubstitution(self, message):
        res = ""
        for c in message:
            if c.islower():
                c = c.upper()
            if c in self.substitution:
                res += self.substitution[c]
            else:
                res += c
        return res

    def reverseSubstitution(self, message):
        res = ""
        for c in message:
            if c.islower():
                c = c.upper()
            if c in self.reverse:
                res += self.reverse[c]
            else:
                res += c
        return res


if __name__ == "__main__":
    subkey = {'A': 'B', 'B': 'C', 'C': 'D', 'D': 'E', 'E': 'F',
              'F': 'G', 'G': 'H', 'H': 'I', 'I': 'J', 'J': 'K',
              'K': 'L', 'L': 'M', 'M': 'N', 'N': 'O', 'O': 'P',
              'P': 'Q', 'Q': 'R', 'R': 'S', 'S': 'T', 'T': 'U',
              'U': 'V', 'V': 'W', 'W': 'X', 'X': 'Y', 'Y': 'Z',
              'Z': 'A'}
    cipher = Substitution(subkey)

    msg = "I am a code breaker"
    print("Message      = {0}".format(msg))
    enc = cipher.makeSubstitution(msg)
    print("Substitution = {0}".format(enc))
    dec = cipher.reverseSubstitution(enc)
    print("Reversed     = {0}".format(dec))
