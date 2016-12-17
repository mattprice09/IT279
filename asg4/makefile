CC=g++

all: GraphMenu.o DisjointSets.o WDGraph.o
	${CC} GraphMenu.o DisjointSets.o WDGraph.o -o asg4

GraphMenu.o: GraphMenu.cpp GraphMenu.h
	${CC} -c GraphMenu.cpp

DisjointSets.o: DisjointSets.cpp DisjointSets.h
	${CC} -c DisjointSets.cpp

WDGraph.o: WDGraph.cpp WDGraph.h
	${CC} -c WDGraph.cpp

clean:
	rm *.o asg4*