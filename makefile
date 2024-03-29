execute: main.o substring.o
	g++ -Wall -g main.o substring.o -o execute

main.o : main.cpp substring.h
	g++ -Wall -g -c main.cpp

substring.o : substring.cpp substring.h
	g++ -Wall -g -c substring.cpp

clean: 
	rm -f execute *.o
