CC=g++

all: Dictionary.o SpellCheck.o
	${CC} Dictionary.o SpellCheck.o -o asg3

Dictionary.o: Dictionary.cpp Dictionary.h
	${CC} -c Dictionary.cpp

SpellCheck.o: SpellCheck.cpp
	${CC} -c SpellCheck.cpp
