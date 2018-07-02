RawData = input()
Data = list(map(int, RawData.split()))

# ======= BUBBLE SORT VERSION A =============
def BubbleSortVersionA(Data):
    for n in range(len(Data), 0, -1):
        for i in range(n - 1):
            if Data[i] > Data[i + 1]:
                Data[i], Data[i + 1] = Data[i + 1], Data[i]

    return Data

# ======= BUBBLE SORT VERSION A =============
def BubbleSortVersionB(Data):
    length = len(Data) - 1
    sorted = False

    while not sorted:
        sorted = True
        for i in range(length):
            if Data[i] > Data[i + 1]:
                Data[i], Data[i + 1] = Data[i + 1], Data[i]
                sorted = False
    return Data


print(BubbleSortVersionA(Data))
print(BubbleSortVersionB(Data))