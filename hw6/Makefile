# $< - first dependency
# $^ - all dependencies
# if included in the .h file then dont need to compile together just puT as dependency and use
# Valgrind variable different from that in command so it doesnt run each time

CXX = g++
CPPFLAGS = -g -Wall
VGA = valgrind --tool=memcheck --leak-check=yes --track-origins=yes


all: Scrabble_funcs AI_Base CPUS Scrabble_obj Scrabble

Scrabble_funcs: Scrabble_funcs.cpp
	$(CXX) $(CPPFLAGS) -c $^ -o Scrabble_funcs.o

#AbstractAI: AbstractAI.h
#$(CXX) $(CPPFLAGS) -c $^ -o AbstractAI.o

AI_Base: AI_Base.cpp
	$(CXX) $(CPPFLAGS) -c $^ -o AI_Base.o

CPUS: CPUS.cpp
	$(CXX) $(CPPFLAGS) -c $^ -o CPUS.o

CPUL: CPUL.cpp
	$(CXX) $(CPPFLAGS) -c $^ -o CPUL.o

Scrabble_obj: Scrabble.cpp
	$(CXX) $(CPPFLAGS) -c $^ -o Scrabble.o
	#./scrabble config.txt

Scrabble: Exceptions.h Util.o Board.o Dictionary.o Tile.h Bag.o Player.o Game.o Move.o AbstractAI.h AI_Base.o CPUS.o CPUL.o Scrabble_funcs.o Scrabble.o
	$(CXX) $(CPPFLAGS) $^ -o Scrabble

clean:
	rm Scrabble_funcs.o
	rm AI_Base.o
	rm CPUS.o
	rm CPUL.o
	rm Scrabble.o
	rm Scrabble
#intermediate compilation