/*
if other = null
+operator
*/

#include "lliststring.h"
#include "gtest/gtest.h"
//#include <iostream>

//all tests should have same name eg FIbtest or whatever 
//i.e. first parameter

//parameter 2 is name of test, can be whatever you want
//expect_eq is expect equal

class lliststringtest : public testing::Test {
protected:
	// You can remove any or all of the following functions if its body is empty.

	lliststringtest() {
		// You can do set-up work for each test here.
	}

	virtual ~lliststringtest() {
		// You can do clean-up work that doesn't throw exceptions here.		
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:
	virtual void SetUp() {
		// Code here will be called immediately after the constructor (right
		// before each test).
	
		 list.insert(0, "Bob the builder");
		 list.insert(1, "Voldemort");
		 list.insert(2, "Gandalf");
		 list.insert(3, "Doge");
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).
		
	}

	// Objects declared here can be used by all tests in the test case.
	LListString list, list_assign, list_add, list_add_tester;
};

TEST_F(lliststringtest, NominalCopyequality) {
	// Exepct 0th element to be 1, 1st elemnt to be 2, etc.
	LListString list_copy(list);
	//EXPECT_EQ(list_copy.size(), list.size());
	//cout<<"segfault";
	for (int i = 0 ; i <list_copy.size() && i <list.size() ; i++) {//since same size should go to larger one
	         EXPECT_EQ(list_copy.get(i), list.get(i));
	}
	 		
}



TEST_F(lliststringtest, NominalCopyDeep) {	
	//after removing from list copy should remain the same
	LListString list_copy(list);
	list.remove(2);
	for (int i = 0 ; i <2 ; i++) {
	        EXPECT_EQ(list_copy.get(i), list.get(i));
	}
	for (int i = 2 ; i <list.size() ; i++) {
	        EXPECT_EQ(list.get(i), list_copy.get(i+1));
	}

	       
}



TEST_F(lliststringtest, Nominalassignmenty) {
   list_assign.insert(0, "0");
   list_assign.insert(1, "1");
   list_assign.insert(2, "2");

     list_assign = list;

     for (int i = 0 ; i <list_assign.size() && i <list.size() ; i++) {//since same size should go to larger one
	         EXPECT_EQ(list_assign.get(i), list.get(i));
	 }

}


TEST_F(lliststringtest, NominalAdd) {
   list_assign.insert(0, "0");
   list_assign.insert(1, "1");
   list_assign.insert(2, "2");


     list_add= list_assign + list;

     for (int i = 0 ; i <list_assign.size(); i++) {
	         EXPECT_EQ(list_assign.get(i), list_add.get(i));
	 }
	 for (int i = 0 ; i <list.size(); i++) {
	         EXPECT_EQ(list_add.get(i+list_assign.size()), list.get(i));
	 }

}


TEST_F(lliststringtest, NominalAccess) {

	for (int i = 0 ; i <list.size(); i++) {
	         EXPECT_EQ(list[i], list.get(i));
	}
	 		
}

