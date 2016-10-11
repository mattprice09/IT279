CC=g++
CFLAGS=-c
OFLAG=-o

build: output

output: calculate.o LLStack.o
	${CC} calculate.o LLStack.o ${OFLAG} output

calculate.o: calculate.cpp
	${CC} ${CFLAGS} calculate.cpp

LLStack.o: LLStack.cpp LLStack.h
	${CC} ${CFLAGS} LLStack.cpp

clean: 
	- rm -rf *.o
