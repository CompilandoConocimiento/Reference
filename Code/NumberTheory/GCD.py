RawData = input()
Data = list(map(int, RawData.split()))

print (Data)

def RecursiveGCDv1(a, b):
    a, b = abs(a), abs(b)
    if a < 1: return b
    if b < 1: return a

    return RecursiveGCDv1(abs(a - b), (min(a, b)))

print (RecursiveGCDv1(Data[0], Data[1]))