# $< - first dependency
# $^ - all dependencies
# if included in the .h file then dont need to compile together just puT as dependency and use
# Valgrind variable different from that in command so it doesnt run each time

CXX = g++
CPPFLAGS = -g -Wall
GTEST = -I /usr/include/gtest/ -l gtest -l gtest_main -pthread
VGA = valgrind --tool=memcheck --leak-check=yes --track-origins=yes


all: AI_Base

AI_Base: AI_Base.h
	$(CXX) $(CPPFLAGS) $^ -o AI_Base



Scrabble: Board.o Dictionary.o Tile.h Bag.o Player.o Scrabble.cpp
	$(CXX) $(CPPFLAGS) $^ -o Scrabble
	#./scrabble config.txt

#intermediate compilation