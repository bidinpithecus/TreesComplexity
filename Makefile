all: plotGraphs

compileGcc:
	@gcc src/*.c -lm -Wall -o main.out

execFile: compileGcc
	@./main.out plotGraphs
	@rm -f main.out

plotGraphs: execFile
	@python3 src/WorstCase.py
	@python3 src/AverageCase.py
