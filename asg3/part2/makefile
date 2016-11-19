CC=g++

all: hash

hash: HashDict.o SpellCheck.o
	${CC} HashDict.o SpellCheck.o -o asg3p2

HashDict.o: HashDict.cpp Dictionary.h
	${CC} -c HashDict.cpp

SpellCheck.o: SpellCheck.cpp
	${CC} -c SpellCheck.cpp

clean:
	rm *.o asg3*