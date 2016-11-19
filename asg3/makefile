CC=g++

all: avl hash

avl: Dictionary.o SpellCheckAVL.o
	${CC} Dictionary.o SpellCheckAVL.o -o asg3

hash: HashDict.o SpellCheck.o
	${CC} HashDict.o SpellCheck.o -o asg3Hash

testHash: Dictionary.o HashDict.o
	${CC} -g Dictionary.o HashDict.o -o testHash

Dictionary.o: Dictionary.cpp Dictionary.h
	${CC} -c Dictionary.cpp

HashDict.o: HashDict.cpp HashDict.h
	${CC} -c HashDict.cpp

SpellCheck.o: SpellCheck.cpp
	${CC} -c SpellCheck.cpp

SpellCheckAVL.o: SpellCheckAVL.cpp
	${CC} -c SpellCheckAVL.cpp

clean:
	rm *.o asg3*