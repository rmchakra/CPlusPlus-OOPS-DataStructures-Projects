all: llist

llist: lliststring_test.cpp
	g++ -g -Wall -c lliststring.cpp -o lliststring.o
	g++ -g -Wall lliststring_test.cpp lliststring.o -o lliststring_test
	valgrind --leak-check=yes --tool=memcheck -v ./lliststring_test
	./lliststring_test

