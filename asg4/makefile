CC=g++

all: WDGraph.o DisjointSets.o
	${CC} WDGraph.o DisjointSets.o -o asg4

DisjointSets.o: DisjointSets.cpp DisjointSets.h
	${CC} -c DisjointSets.cpp

WDGraph.o: WDGraph.cpp WDGraph.h
	${CC} -c WDGraph.cpp

clean:
	rm *.o asg4*