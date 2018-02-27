import sys

def CesarCipher(NormalData, Key):
    ChiperData = ""
    for char in NormalData:
        nextValue = ord(char) + Key
        if (nextValue > ord('z')):
            nextValue = ord('a') + (nextValue - ord('z') - 1)
        ChiperData += chr(nextValue)

    return ChiperData

for Line in sys.stdin:
    Line = Line.split()
    NormalData, Key = Line[0], int(Line[1])

    print(f"{CesarCipher(NormalData, Key)} {Key}")