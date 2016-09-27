GTEST_LL = -I /usr/include/gtest/ -l gtest -l gtest_main -pthread

all: llist

llist: lliststring_test.cpp
	g++ -g -Wall -c lliststring.cpp -o lliststring.o
	g++ -g -Wall llisttest.cpp lliststring.o $(GTEST_LL) -o llisttest
	valgrind --leak-check=yes --tool=memcheck -v ./llisttest
	./llisttest

