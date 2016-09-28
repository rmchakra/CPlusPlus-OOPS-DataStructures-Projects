/*
if other = null
+operator
*/

#include "stringparser.cpp"
#include "gtest/gtest.h"

//all tests should have same name eg FIbtest or whatever 
//i.e. first parameter

//parameter 2 is name of test, can be whatever you want
//expect_eq is expect equal

class stringparsertest : public testing::Test {
protected:
	// You can remove any or all of the following functions if its body is empty.

	stringparsertest() {
		// You can do set-up work for each test here.
	}

	virtual ~stringparsertest() {
		// You can do clean-up work that doesn't throw exceptions here.		
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:
	virtual void SetUp() {
		// Code here will be called immediately after the constructor (right
		// before each test).
	/*
		 stack.push("Bob the builder");
		 stack.push( "Voldemort");
		 stack.push( "Gandalf");
		 stack.push( "Doge");
	*/
		 str_arr[0]="Bob the builder";
		 str_arr[1]="Voldemort";
		 str_arr[2]="Gandalf";
		 str_arr[3]="Doge";
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).
		
	}

	// Objects declared here can be used by all tests in the test case.
	StackString stack;
	std::string str_arr[4];
};

TEST_F(stringparsertest, Boundrypush) {
	//first push
	stack.push("Doge");
	//EXPECT_EQ(list_copy.size(), list.size());
	//cout<<"segfault";
	  EXPECT_EQ(stack.top(), str_arr[3]);
}



TEST_F(stringparsertest, Nominalpush) {	
	//2nd push
		   stack.push("Doge");
	       stack.push(str_arr[2]);
	       EXPECT_EQ(stack.top(), str_arr[2]);
}


TEST_F(stringparsertest, pop) {
   stack.push(str_arr[3]);
   stack.push(str_arr[2]);
   stack.push(str_arr[1]);
   stack.push(str_arr[0]);

     for (int i = 0 ; i <4  ; i++) {
     //poping all and checking fo equality of top to each array element

	         EXPECT_EQ(stack.top(), str_arr[i]);
	         stack.pop();
	 }
	 stack.pop();
	 stack.pop();

}