RawData = input()
Data = list(map(int, RawData.split()))


for i, element1 in enumerate(Data):
    for j, element2 in enumerate(Data[ : -i]):
        if element1 < element2:
            Data[i] , Data[j] = Data[j], Data[i]

print(Data)