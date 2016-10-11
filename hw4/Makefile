# $< - first dependency
# $^ - all dependencies

CXX = g++
CPPFLAGS = -g -Wall
GTEST = -I /usr/include/gtest/ -l gtest -l gtest_main -pthread
VG = valgrind --tool=memcheck --leak-check=yes --track-origins=yes


all: Reset Board Dictionary Bag  Player Scrabble clean

Reset: 
	reset
	
Board: Board.cpp
	$(CXX) $(CPPFLAGS) -c $^ -o Board.o	

Dictionary: Dictionary.cpp 
	$(CXX) $(CPPFLAGS) -c $< -o Dictionary.o

#	$(CXX) $(CPPFLAGS) $< -o Tile.o

Bag: Bag.cpp Tile.h
	$(CXX) $(CPPFLAGS) -c $< -o Bag.o

Player: Player.cpp Player.h
	$(CXX) $(CPPFLAGS) -c $< -o Player.o	

Scrabble: Board.o Dictionary.o Tile.h Bag.o Player.o Scrabble.cpp
	$(CXX) $(CPPFLAGS) $^ -o scrabble
#	./scrabble config.txt

#intermediate compilation

clean:
	rm Board.o
	rm Dictionary.o
	rm Bag.o
	rm Player.o
	rm scrabble