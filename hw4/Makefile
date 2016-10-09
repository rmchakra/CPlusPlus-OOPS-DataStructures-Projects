# $< - first dependency
# $^ - all dependencies


CXX = g++
CPPFLAGS = -g -Wall
GTEST = -I /usr/include/gtest/ -l gtest -l gtest_main -pthread
VG = valgrind --tool=memcheck --leak-check=yes --track-origins=yes


all: Player Tile  Bag Board Dictionary Scrabble
	
Dictionary: Dictionary.cpp 
	$(CXX) $(CPPFLAGS) -c $< -o Dictionary.o

Tile: Tile.h
	$(CXX) $(CPPFLAGS) $^ -o Tile.o

Bag: Bag.cpp Tile.o
	$(CXX) $(CPPFLAGS) -c $^ -o Bag.o

Board: Board.cpp
	$(CXX) $(CPPFLAGS) -c $^ -o Board.o	

Player: Player.h Bag.o Tile.o
	$(CXX) $(CPPFLAGS) -c $^ -o Player.o	

Scrabble: Player.o Tile.o  Bag.o Board.o Dictionary.o Scrabble.cpp
	$(CXX) $(CPPFLAGS) $^ -o scrabble
	./scrabble config.txt
clean:
	rm dictionary.o
	rm tile.o
	rm bag.o
	rm board.o
	rm Player.o
	rm scrabble