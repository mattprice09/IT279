CC=g++

all: Dictionary.o HashDict.o SpellCheck.o
	${CC} Dictionary.o HashDict.o SpellCheck.o -o asg3

avl: Dictionary.o SpellCheck.o
	${CC} Dictionary.o SpellCheck.o -o asg3

testHash: Dictionary.o HashDict.o
	${CC} -g Dictionary.o HashDict.o -o testHash

Dictionary.o: Dictionary.cpp Dictionary.h
	${CC} -c Dictionary.cpp

HashDict.o: HashDict.cpp HashDict.h
	${CC} -c HashDict.cpp

SpellCheck.o: SpellCheck.cpp
	${CC} -c SpellCheck.cpp
