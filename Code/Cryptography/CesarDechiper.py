import sys

def CesarDeCipher(ChiperData, Key):
    NormalData = ""
    for char in ChiperData:
        nextValue = ord(char) - Key
        if (nextValue < ord('a')):
            nextValue = ord('z') - (ord('a') - nextValue - 1)
        NormalData += chr(nextValue)

    return NormalData

for Line in sys.stdin:
    Line = Line.split()
    ChiperData, Key = Line[0], int(Line[1])

    print(f"{CesarDeCipher(ChiperData, Key)} {Key}")