#====================================================================
#==================      INSERTION SORT          ====================
#====================================================================
def InsertionSort(Data):                                            #= SELECTION SORT ===
    """
    This is a really intuitive sorting algorithm, to do so we say
    that we will create a new subarray.
    So the subarray [0, 1] is already sorted, now:
    Take the next element contiguos to the subarray an put it where it
    belongs and move all the other 1 place.
    Now my new subarray is from [0, 2], and repeat, you get the point
    
    Args:
        Data (list of int / doubles):  A list to Sort

    Returns:
        List of int / doubles: The sorted list
    """

    SortedData = list(Data)

    for i in range(1, len(Data)):                                   #Traverse each item

        Key = SortedData[i];                                        #Lets put the key
        j = i - 1;                                                  #Let m = A[0..i-1]

        while (j >= 0 and Key < SortedData[j]):                     #Move elements of m
            SortedData[j + 1] = SortedData[j];                      #To one element ahead
            j = j - 1;                                              #ForEach element of m

        SortedData[j + 1] = Key;                                    #Put there Datasize

    return SortedData                                               #Return the sorted data



# =========================================
# ===========   TEST SCRIPT     ===========
# =========================================

A = []

print("Give me all the intergers you want, finish in -1")

while (True):
    x = int(input())
    if x == -1: break
    A.append(x)

B = InsertionSort(A)

print(F"Original Data is {A}")
print(F"Sorted Array is {B}")