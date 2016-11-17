CC=g++

all: AVLDictionary.o SpellCheck.o
	${CC} AVLDictionary.o SpellCheck.o -o asg3

AVLDictionary.o: AVLDictionary.cpp AVLDictionary.h
	${CC} -c AVLDictionary.cpp

SpellCheck.o: SpellCheck.cpp
	${CC} -c SpellCheck.cpp
