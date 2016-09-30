GTEST_LL = -I /usr/include/gtest/ -l gtest -l gtest_main -pthread

all: llist stackstring stringparser

llist: lliststring_test.cpp
	g++ -g -Wall -c lliststring.cpp -o lliststring.o
	g++ -g -Wall llisttest.cpp lliststring.o $(GTEST_LL) -o llisttest
	valgrind --leak-check=yes --tool=memcheck  --track-origins=yes ./llisttest
	./llisttest

stackstring: stackstringtest.cpp
	g++ -g -Wall -c lliststring.cpp -o lliststring.o
	g++ -g -Wall -c stackstring.cpp -o stackstring.o
	g++ -g -Wall stackstring.o lliststring.o stackstringtest.cpp $(GTEST_LL) -o stackstringtest
	valgrind --leak-check=yes --tool=memcheck  --track-origins=yes ./stackstringtest
	./stackstringtest

stringparser: stringparser.cpp
	reset
	g++ -g -Wall stringparser.cpp -o stringparser
	valgrind --leak-check=yes --tool=memcheck  --track-origins=yes ./stringparser hw3_destroyer.in hw3_destroyer_out.txt
	./stringparser hw3_destroyer.in hw3_destroyer_out.txt
	
	