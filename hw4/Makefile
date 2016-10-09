# $< - first dependency
# $^ - all dependencies


CXX = g++
CPPFLAGS = -g -Wall
GTEST = -I /usr/include/gtest/ -l gtest -l gtest_main -pthread
VG = valgrind --tool=memcheck --leak-check=yes --track-origins=yes


"Tile.h"
#include "Dictionary.h"
#include "Bag.h"
#include "Board.h"

all: Player Tile  Bag Board Dictionary Scrabble

Player: 
	
Dictionary: lliststring.cpp lliststring.h 
	$(CXX) $(CPPFLAGS) -c $< -o lliststring.o
Tile: llisttest.cpp lliststring.o
	$(CXX) $(CPPFLAGS) $^ $(GTEST_LL) -o llisttest
	$(VALG) ./llisttest
Bag: stackstring.cpp 
	$(CXX) $(CPPFLAGS) -c $< -o stackstring.o

Board: 

Scrabble: stringparser.cpp lliststring.cpp
	$(CXX) $(CPPFLAGS) $^ -o stringparser
	./stringparser hw3_destroyer.in output.out
clean:
	rm dictionary.o
	rm tile.o
	rm bag.o
	rm board.o
	rm scrabble