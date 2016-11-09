# $< - first dependency
# $^ - all dependencies
# if included in the .h file then dont need to compile together just puT as dependency and use
# Valgrind variable different from that in command so it doesnt run each time

CXX = g++
CPPFLAGS = -g -Wall
VGA = valgrind --tool=memcheck --leak-check=yes --track-origins=yes


all: Scrabble_funcs AI_Base Scrabble_obj Scrabble

Scrabble_funcs: Scrabble_funcs.cpp
	$(CXX) $(CPPFLAGS) -c $^ -o Scrabble_funcs.o


AI_Base: AI_Base.cpp
	$(CXX) $(CPPFLAGS) -c $^ -o AI_Base.o


Scrabble_obj: Scrabble.cpp Board.o Dictionary.o Tile.h Bag.o Player.o AI_Base.o Scrabble_funcs.o 
	$(CXX) $(CPPFLAGS) -c $< -o Scrabble.o
	#./scrabble config.txt

Scrabble: Util.o Board.o Dictionary.o Tile.h Bag.o Player.o Game.o Move.o AI_Base.o Scrabble_funcs.o Scrabble.o
	$(CXX) $(CPPFLAGS) $^ -o Scrabble

#intermediate compilation