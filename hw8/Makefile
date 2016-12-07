CXX = g++
CPPFLAGS = -g -O2 -Wall -std=c++11
#add -O2 between -g and -Wall
#etext reps alternates between 1 and 9 but should be 16
#both quad and double hash dont work since theyre looping.


VGA = valgrind --tool=memcheck --leak-check=yes --track-origins=yes
GTEST = -I /usr/include/gtest/ -l gtest -l gtest_main -pthread

all: HASHTABLE_OBJ counting
#HASHTABLE - for main class that does nothing
#TEST - 

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

counting: Hashtable.cpp counting.cpp
	$(CXX) $(CPPFLAGS) -c $< -o Hashtable.o
	$(CXX) $(CPPFLAGS) Hashtable.o counting.cpp -o counting


clean: 
	rm q3_tester.o
	rm Hashtable.o
	rm HASHTABLE

	#make hash private again