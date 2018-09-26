compilers = g++-7
flags = -std=c++17 -Wall
outputName = MatrixTest
fileName = index.cpp

Compile:
	$(compilers) $(fileName) $(flags) -o $(outputName)

CompileAndRun: 
	$(compilers) $(fileName) $(flags) -o $(outputName)
	clear
	sleep 3
	./$(outputName)