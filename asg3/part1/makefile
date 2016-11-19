CC=g++

all: avl

avl: Dictionary.o SpellCheck.o
	${CC} Dictionary.o SpellCheck.o -o asg3p1

Dictionary.o: Dictionary.cpp Dictionary.h
	${CC} -c Dictionary.cpp

SpellCheck.o: SpellCheck.cpp
	${CC} -c SpellCheck.cpp

clean:
	rm *.o asg3*