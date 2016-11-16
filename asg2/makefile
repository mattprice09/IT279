all: InsertionSort ShellSort BottomUpMergesort

debug: InsertionSort.cpp InsertionSort.h
	g++ -g -o InsertionSort InsertionSort.cpp

InsertionSort: InsertionSort.cpp InsertionSort.h
	g++ -o InsertionSort InsertionSort.cpp

ShellSort: ShellSort.cpp ShellSort.h
	g++ -o ShellSort ShellSort.cpp

BottomUpMergesort: BottomUpMergesort.o BottomUp.o
	g++ -o BottomUpMergesort BottomUpMergesort.o BottomUp.o

BottomUpMergesort.o: BottomUpMergesort.cpp
	g++ -c BottomUpMergesort.cpp

BottomUp.o: BottomUp.cpp
	g++ -c BottomUp.cpp

clean:
	rm *.exe