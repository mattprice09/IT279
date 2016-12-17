CC=g++
CFLAGS=-c
OFLAG=-o

build: output

output: supermarket.o LLQueue.o
	${CC} supermarket.o LLQueue.o ${OFLAG} output
	
LLQueue.o: LLQueue.cpp LLQueue.h
	${CC} ${CFLAGS} LLQueue.cpp

supermarket.o: supermarket.cpp
	${CC} ${CFLAGS} supermarket.cpp

clean: 
	- rm -rf *.o
