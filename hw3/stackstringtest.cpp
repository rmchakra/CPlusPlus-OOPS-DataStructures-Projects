/*
if other = null
+operator
*/

#include "stackstring.h"
#include "gtest/gtest.h"

//all tests should have same name eg FIbtest or whatever 
//i.e. first parameter

//parameter 2 is name of test, can be whatever you want
//expect_eq is expect equal

class stackstringtest : public testing::Test {
protected:
	// You can remove any or all of the following functions if its body is empty.

	stackstringtest() {
		// You can do set-up work for each test here.
	}

	virtual ~stackstringtest() {
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

TEST_F(stackstringtest, Boundrypush) {
	//first push
	stack.push("Bob the builder");
	//EXPECT_EQ(list_copy.size(), list.size());
	//cout<<"segfault";
	  EXPECT_EQ(stack.top(), str_arr[0]);
}
/*


TEST_F(stackstringtest, NominalCopyDeep) {	
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


TEST_F(stackstringtest, Nominalassignmenty) {
   list_assign.insert(0, "0");
   list_assign.insert(1, "1");
   list_assign.insert(2, "2");

     list_assign = list;

     for (int i = 0 ; i <list_assign.size() && i <list.size() ; i++) {
     //and ensures both variables are of same size else would seg fault
	         EXPECT_EQ(list_assign.get(i), list.get(i));
	 }

}


TEST_F(stackstringtest, NominalAdd) {
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


TEST_F(stackstringtest, NominalAccess) {

	for (int i = 0 ; i <list.size(); i++) {
	         EXPECT_EQ(list[i], list.get(i));
	}
	 		
}

TEST_F(stackstringtest, offNominalAssignEqual) {
	LListString old_list = list;
	list=list;
	for (int i = 0 ; i <list.size(); i++) {
	         EXPECT_EQ(list[i], old_list.get(i));
	}
}

TEST_F(stackstringtest, BoundryAssignEmpty) {
//equating to empty list
	list=list_assign;//list should be empty
	         EXPECT_EQ(true, list.empty() );
	     }
*/
/*	     
TEST_F(lliststringtest, BoundryAddEmptyToItself) {
	LListString old_list = list;
	list=list+list_assign;//list_assign is empty
	for (int i = 0 ; i <list.size(); i++) {
	         EXPECT_EQ(list[i], old_list.get(i));
	}
}
TEST_F(lliststringtest, BoundryAddEmptyToEmptyItself) {
	//adding empty to empty and storing
	LListString old_list = list;
	list=list_assign+list_assign;//list_assign is empty
	
	         EXPECT_EQ(true, list.empty());
}

TEST_F(lliststringtest, offNominalAddtoItselfandStoreInItself) {
	LListString old_list = list;
	list=list+list;//adding to itself and storing in itself
	for (int i = 0 ; i <old_list.size(); i++) {
	         EXPECT_EQ(list[i], old_list.get(i));
	}//checkibng each half of double the list as equal to the list
	for (int i = 0 ; i <old_list.size(); i++) {
	         EXPECT_EQ(list[i+old_list.size()], old_list.get(i));
	}
}
TEST_F(lliststringtest, BoundryAcess0) {
	//first element access
	         EXPECT_EQ(list[0], "Bob the builder");
}
TEST_F(lliststringtest, BoundryAcessTail) {
	//tail access
	         EXPECT_EQ(list[list.size()-1],"Doge" );
}
TEST_F(lliststringtest, BoundryConstructor1Element) {
	//single element constructor
	LListString single_element_list;
	single_element_list.insert(0, "0");
	LListString constr(single_element_list);
	EXPECT_EQ(constr.size(),1 );//checking size of 1 element
	EXPECT_EQ(constr[0],"0" );//checking size of 1 element
}
TEST_F(lliststringtest, OffNominalEmptyListConstructed) {
	//empty linked list copy constuctor
	LListString constr(list_assign);//list_assign is an empty list
	EXPECT_EQ(constr.size(),0);//checking size of 1 element
}

*/

