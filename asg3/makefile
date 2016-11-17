CC=g++

all: AVLDict.o HashDict.o SpellCheck.o
	${CC} AVLDict.o HashDict.o SpellCheck.o -o asg3

AVLDict.o: AVLDict.cpp AVLDict.h
	${CC} -c AVLDict.cpp

HashDict.o: HashDict.cpp HashDict.h
	${CC} -c HashDict.cpp

SpellCheck.o: SpellCheck.cpp
	${CC} -c SpellCheck.cpp
