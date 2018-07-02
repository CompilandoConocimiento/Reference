

def RecursiveExp(Base, Exp):
    """
    This function return Base^Exp using a recursive
    implementation, please dont use if you care at all
    in speed performace or if you love you function stack :)

    Args:
        Base (int, float):  The base 
        Exp (int):          The exponent

    Returns:
        int, float:  base^exponent
    """
    if Exp == 1:
        return Base

    return Base * RecursiveExp(Base, Exp - 1)

def BinaryExponentation(Base, Exponent):        #FN: Binary Exponentation: a^b
    """
    HOW IT WORK:
    This function will POW(a,b) but a little bit more fast using
        Exponentation by Squaring 

        Math Observation:
                x (x^2)^((n-1)/2)   if n is odd
        x^n =
                (x^2)^(n/2)         if n is even

    Thanks to the math identity we create an algoritm that always works:

    ALGORITM: This deduced from the V1:
        Start solution to 0
        Start auxiliar to base
        For each bit in exponent (Starting at the least important one):
            If is 1:
                Update solution = auxiliar * solution
                Update auxiliar = auxiliar^2
            If is 0:
                Update auxiliar = auxiliar^2

    Args:
        Base (int, float):  The base 
        Exponent (int):     The exponent

    Returns:
        int, float:  base^exponent
    """
    Solution = 1                                #Auxiliar variables for code clarity
    Auxiliar = Base                             #Auxiliar variables for code clarity

    while (Exponent != 0):                      #End were exponent is zero

        if (Exponent & 1):                      #If Exponent last digit = 1 (Exp is odd):
            Solution = Auxiliar * Solution      #Update Solution
            Auxiliar = Auxiliar * Auxiliar      #Always update by squaring the aux variable
            Exponent = Exponent >> 1            #Remove 1 digit from e to read the next one
        else :                                  #If Exponent is even:
            Auxiliar = Auxiliar * Auxiliar      #Always update by squaring the aux variable
            Exponent = Exponent >> 1            #Remove 1 digit from e to read the next one
        

    return Solution                             #Return solution




# =========================================
# ===========   TEST SCRIPT     ===========
# =========================================

TestData = list(map(int, input("Give 2 intergers: ").split()))

print(F"{TestData[0]} ^ {TestData[1]} = ")
print(F"By BinaryExponentation is {BinaryExponentation(TestData[0], TestData[1])}")
print(F"By Recursive Exponentation is {RecursiveExp(TestData[0], TestData[1])}")