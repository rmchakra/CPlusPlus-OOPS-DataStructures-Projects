#for AVLBST

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
	#./AVLBST hw7_destroyer.in sky_out.txt


clean: 
	rm AVLBST