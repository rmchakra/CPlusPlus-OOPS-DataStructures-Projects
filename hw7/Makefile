CXX = g++
CPPFLAGS = -g -Wall
VGA = valgrind --tool=memcheck --leak-check=yes --track-origins=yes

all: BST

BST: p2_main.cpp
	$(CXX) $(CPPFLAGS) $^ -o BST
	#./BST