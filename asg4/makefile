CC=g++

all: DisjointSets.o WDGraph.o
	${CC} DisjointSets.o WDGraph.o -o asg4

DisjointSets.o: DisjointSets.cpp DisjointSets.h
	${CC} -c DisjointSets.cpp

WDGraph.o: WDGraph.cpp WDGraph.h
	${CC} -c WDGraph.cpp

clean:
	rm *.o asg4*