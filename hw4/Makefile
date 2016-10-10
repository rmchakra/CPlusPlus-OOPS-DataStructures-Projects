# $< - first dependency
# $^ - all dependencies


CXX = g++
CPPFLAGS = -g -Wall
GTEST = -I /usr/include/gtest/ -l gtest -l gtest_main -pthread
VG = valgrind --tool=memcheck --leak-check=yes --track-origins=yes


all: Board Scrabble clean
	
Board: Board.cpp
	$(CXX) $(CPPFLAGS) -c $^ -o Board.o	

Scrabble: Board.o Scrabble.cpp
	$(CXX) $(CPPFLAGS) $^ -o scrabble
	$(VG) ./scrabble config.txt

#intermediate compilation

clean:
	rm Board.o
	rm scrabble