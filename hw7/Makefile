CXX = g++
CPPFLAGS = -g -Wall
VGA = valgrind --tool=memcheck --leak-check=yes --track-origins=yes

all: RESET BST

RESET: 
		reset

BST: p2_main.cpp
	$(CXX) $(CPPFLAGS) $^ -o BST
	#./BST

clean: 
	rm BST