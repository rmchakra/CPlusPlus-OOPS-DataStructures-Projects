CXX = g++
CPPFLAGS = -g -Wall -std=c++11
VGA = valgrind --tool=memcheck --leak-check=yes --track-origins=yes

all: CLEAR HASHTABLE_OBJ HASHTABLE

CLEAR:
	  clear

RESET: 
		reset

HASHTABLE_OBJ: Hashtable.cpp
	$(CXX) $(CPPFLAGS) -c $< -o Hashtable.o

HASHTABLE: q3_tester.cpp Hashtable.o
	$(CXX) $(CPPFLAGS) $^ -o HASHTABLE


clean: 
	rm HASHTABLE