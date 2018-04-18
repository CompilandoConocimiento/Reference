# Test Example


## Test Compile
	
~~~~
gcc -std=c11 Time.c TestSearchAlgorithms.c -o TestSearchAlgorithms -pthread
~~~~

## Test Run

~~~~
./TestSearchAlgorithms 10000 0 9 Cases.txt Out.txt < Input10MillionSorted.txt
~~~~