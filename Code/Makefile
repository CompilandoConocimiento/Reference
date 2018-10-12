compiler = g++-8
flags = -std=c++17 -Wall
outputName = program
fileName = index.cpp

compile:
	$(compiler) $(fileName) $(flags) -o $(outputName)

compileRun: 
	$(compiler) $(fileName) $(flags) -o $(outputName)
	clear
	sleep 2
	./$(outputName)