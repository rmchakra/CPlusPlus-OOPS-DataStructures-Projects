CXX = g++
CPPFLAGS = -g -Wall -std=c++11
VGA = valgrind --tool=memcheck --leak-check=yes --track-origins=yes
GTEST = -I /usr/include/gtest/ -l gtest -l gtest_main -pthread

all: CLEAR HASHTABLE_OBJ Q3_TESTER TEST
#HASHTABLE - for main class that does nothing
#TEST - 

CLEAR:
	  clear

RESET: 
		reset

HASHTABLE_OBJ: Hashtable.cpp
	$(CXX) $(CPPFLAGS) -c $< -o Hashtable.o

Q3_TESTER: q3_tester.cpp
	$(CXX) $(CPPFLAGS) -c $< -o q3_tester.o

TEST: hash_test.cpp Hashtable.o
	$(CXX) $(CPPFLAGS)  $^ $(GTEST) -o HASHTABLE


HASHTABLE: q3_tester.o Hashtable.o
	$(CXX) $(CPPFLAGS) $^ -o HASHTABLE


clean: 
	rm q3_tester.o
	rm Hashtable.o
	rm HASHTABLE