#long long x = 9223372036854775807;//2^63 - 1
#to access mRoot do this->mRoot since youre in AVLBST and need to access mother class BST

CXX = g++
CPPFLAGS = -g -Wall -std=c++11
VGA = valgrind --tool=memcheck --leak-check=yes --track-origins=yes

all: CLEAR BST

CLEAR:
	  clear

RESET: 
		reset

BST: p2_main.cpp
	$(CXX) $(CPPFLAGS) $^ -o AVLBST
	#./AVLBST


clean: 
	rm AVLBST