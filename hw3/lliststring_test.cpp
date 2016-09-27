/*
	test case summary
	inserting head for empty list
	inserting at negative and greater than size
	inserting 2nd element at head position and checking shift
	Inserting at tail

	removing invalid positions
	removing head
	removing middle
	removing tail
	removing last element of the list
	removing from empty list

*/

#include "lliststring.h"
#include <iostream>

using namespace std;

int main() {
  LListString* list = new LListString();

  // Check if the list is initially empty.
  if (list->empty()) {
    cout << "SUCCESS: List is empty initially." << endl;
  } else {
    cout << "FAIL: List is not empty initially when it should be." << endl;
  }

 
//##########################################################################################
  // Insert an item at the head.
  list->insert(0, "Gandalf");

  // Check if the list is still empty.
  if (!list->empty()) 
  {
    cout << "SUCCESS: List is not empty after one insertion." << endl;
  } 
  else
   {
    cout << "FAIL: List is empty after one insertion." << endl;
  }

  if (list->size() == 1) 
  {
    cout << "SUCCESS: List has size 1 after one insertion." << endl;
  }
   else 
  {
    cout << "FAIL: List has size " << list->size() << " after one insertion.";
    cout << endl;
  }

  // Check if the value is correct.
  if (list->get(0) == "Gandalf")
   {
    cout << "SUCCESS: Gandalf is at the 0th index of the list." << endl;
  } 
  else 
  {
    cout << "FAIL: Gandalf is not at the 0th index of the list, " << list->get(0);
    cout << " is instead." << endl;
  }

  // TODO: Continue adding tests for your program, or start your own file with your
  // own tests. Remember to submit a file that is named correctly!

  
//##########################################################################################

 //inserting at invalid positions
	list->insert(-1, "-1");
	list->insert(3, "1");
	//invalid since current size of list is 1

  if (list->size() == 1) 
  {
    cout << "SUCCESS: List Continues having size 1 after wrong insertion." << endl;
  } 
  else 
  {
    cout << "FAIL: List has size " << list->size() << " after one insertion.";
    cout << endl;
  }

  if (list->get(0) == "Gandalf") 
  {
     cout << "SUCCESS: Gandalf has not shifted from 0th index of the";
     cout <<"list after unsucessful insertion." << endl;
  } 
  else 
  {
    cout << "FAIL: Gandalf has shifted 0th index of the list, " << list->get(0);
    cout << " is instead." << endl;
  }


//##########################################################################################
  //inserting at head

  list->insert(0, "Bob the builder");

  if ( (list->get(0) == "Bob the builder") && ((list->get(1) == "Gandalf") ))
  {
    cout << "SUCCESS: Bob the builder passed Gandalf -";
     cout << "inserting at head with head present and checking if head shifted ahead"<< endl;
  } 
  else 
  {
    cout << "FAIL: Bob not at 0 and Gandalf not at 1 when inserting Bob after Gandalf" << list->get(0);
    cout << " is instead." << endl;
  }

   if (list->size() == 2) 
   {
    cout << "SUCCESS: List has size 2 after second insertion." << endl;
  }
   else 
   {
    cout << "FAIL: List has size " << list->size() << " after 2nd insertion.";
    cout << endl;
  }

//##########################################################################################
//inserting at tail
  list->insert(2, "Doge");

  if ( (list->get(0) == "Bob the builder") && (list->get(1) == "Gandalf" ) && (list->get(2) == "Doge" ))
  {
    cout << "SUCCESS: Doge caught his tail - Added element to the tail"<< endl;
  } 
  else 
  {
    cout << "FAIL: Bob not at 0 or Gandalf not at 1 Doge not at 2 when";
    cout<< "inserting Bob after Gandalf" << list->get(0);
    cout << " is at 0." <<list->get(1)<< "is at 1"<< list->get(2)<< "is at 2"<< endl;
  }

   if (list->size() == 3) 
   {
    cout << "SUCCESS: List has size 3 after tail insertion." << endl;
  }
   else 
   {
    cout << "FAIL: List has size " << list->size() << " after 3rd insertion."<< endl;
    cout << endl;
  }
//##########################################################################################
  //inserting in middle - current list  Bob the builder,Voldemort,Gandalf, Doge
  list->insert(1, "Voldemort");

  if ( (list->get(0) == "Bob the builder") && (list->get(1) == "Voldemort" ) && (list->get(2) == "Gandalf" ))
  {
    cout << "SUCCESS: Voldemort has been named - Added element to middle of list"<< endl;
  } 
  else 
  {
    cout << "FAIL: 0="<< list->get(0) << "1=" <<list->get(1)<< "2="<< list->get(2)<<  endl;
  }

   if (list->size() == 4) 
   {
    cout << "SUCCESS: List has size 4 after middle insertion." << endl;
  }
   else 
   {
    cout << "FAIL: List has size " << list->size() << " after 4th insertion."<< endl;
    cout << endl;
  }
//##########################################################################################
 //current list  Bob the builder,Voldemort,Gandalf, Doge
 //removing invalid positions - current list size is 4, so 5 and -1
 
  LListString* list_copy = new LListString(*list);
  //dereferencing

  list->remove(-1);
  list->remove(5);
  

  if ( (list->get(0) == "Bob the builder") && (list->get(1) == "Voldemort" ) && (list->get(2) == "Gandalf" )
  	&& (list->get(3) == "Doge"))
  {
    cout << "SUCCESS: invalid remove caused no changes"<< endl;
  } 
  else 
  {
    cout << "FAIL :list was modified"<<  endl;
  }

   if (list->size() == 4) 
   {
    cout << "SUCCESS: Diet or Pizza? size is unmodified by invalid removal." << endl;
  }
   else 
   {
    cout << "FAIL: List has size " << list->size() << endl;
    cout << endl;
  }



//##########################################################################################

   //current list  Voldemort,Gandalf, Doge
 //removing invalid positions - current list size is 4, so 5 and -1
 
 //LListString* list_copy = new LListString(list);
  list->remove(0);
  

  if ( (list->get(0) == "Voldemort" ) && (list->get(1) == "Gandalf" )
  	&& (list->get(2) == "Doge"))
  {
    cout << "SUCCESS: Dobby is no longer a free elf : succesful head removal"<< endl;
  } 
  else 
  {
    cout << "FAIL: Harry! Harry! : Head removal failed"<<  endl;
  }

   if (list->size() == 3) 
   {
    cout << "SUCCESS:Not Kale again- size reduced sucessfully by removal." << endl;
  }
   else 
   {
    cout << "FAIL: List has size " << list->size() << endl;
    cout << endl;
  }

//##########################################################################################

  //current list  Voldemort, Doge
 //removing middle

  list->remove(1);
  

  if ( (list->get(0) == "Voldemort" ) && (list->get(1) == "Doge"))
  {
    cout << "SUCCESS: Gandalf passed away : succesful middle removal"<< endl;
  } 
  else 
  {
    cout << "FAIL: You shall not pass : middle there"<<  endl;
  }

   if (list->size() == 2) 
   {
    cout << "SUCCESS:Fancy French Restaurants- size reduced sucessfully by removal." << endl;
  }
   else 
   {
    cout << "FAIL: - Gandalf be chillin : List has size " << list->size() << endl;
    cout << endl;
  }

//##########################################################################################
  //current list  Voldemort
 //removing tail

  list->remove(1);
  

  if (list->get(0) == "Voldemort" ) 
  {
    cout << "SUCCESS: Nose rings banned : succesful tail removal"<< endl;
  } 
  else 
  {
    cout << "FAIL: Tail removal failed"<<  endl;
  }

   if (list->size() == 1) 
   {
    cout << "SUCCESS:Roll Models be like: size 1" << endl;
  }
   else 
   {
    cout << "FAIL:size reduction post tail removal failed" << list->size() << endl;
    cout << endl;
  }

//##########################################################################################
  //current list  NULL
 //removing last element of list

  list->remove(0);
  //list->remove(0);
  
   if (list->size() == 0) 
   {
    cout << "SUCCESS:Nobody exists : removal from empty list didnt occur" << endl;
  }
   else 
   {
    cout << "FAIL:removal from empty list tried to occur" << list->size() << endl;
    cout << endl;
  }
//##########################################################################################
  //current list  NULL
 //removing from empty list

  list->remove(0);
  //list->remove(0);
  
   if (list->size() == 0) 
   {
    cout << "SUCCESS: removal from empty list didnt occur" << endl;
  }
   else 
   {
    cout << "FAIL:removal from empty list tried to occur" << list->size() << endl;
    cout << endl;
  }

//################################################################################
//new list test

   if ( (list_copy->get(0) == "Bob the builder") && (list_copy->get(1) == "Voldemort" ) && (list_copy->get(2) == "Gandalf" )
    && (list_copy->get(3) == "Doge"))
  {
    cout << "SUCCESS: Copy constructor worked"<< endl;
  } 
  else 
  {
    cout << "FAIL :copy constructor failed"<<  endl;
  }

   if (list_copy->size() == 4) 
   {
    cout << "SUCCESS: correct copy constructor size" << endl;
  }
   else 
   {
    cout << "FAIL: List has size " << list_copy->size() << endl;
    cout << endl;
  }

//########################################
//new list assignment test (=)

   LListString* list_assign = new LListString();
   list_assign->insert(0, "0");
   list_assign->insert(1, "1");
   list_assign->insert(2, "2");

   cout<<"pre assignment values"<<endl;
   cout<<"0th  "<<list_assign->get(0)<<endl;
   cout<<"1st  "<<list_assign->get(1)<<endl;
   cout<<"2nd  "<<list_assign->get(2)<<endl;

   cout<<"post assignment"<<endl;
   *list_assign = *list_copy;
   cout<<"0th  "<<list_assign->get(0)<<endl;
   cout<<"1st  "<<list_assign->get(1)<<endl;
   cout<<"2nd  "<<list_assign->get(2)<<endl;

/*
  cout<<"new"<<endl;

   if ( (list_copy->get(0) == "Bob the builder") && (list_copy->get(1) == "Voldemort" ) && (list_copy->get(2) == "Gandalf" )
    && (list_copy->get(3) == "Doge"))
  {
    cout << "SUCCESS: Copy constructor worked"<< endl;
  } 
  else 
  {
    cout << "FAIL :copy constructor failed"<<  endl;
  }

   if (list_copy->size() == 4) 
   {
    cout << "SUCCESS: correct copy constructor size" << endl;
  }
   else 
   {
    cout << "FAIL: List has size " << list_copy->size() << endl;
    cout << endl;
  }

  */

//########################################

/*
//+ into empty

   LListString* list_assign = new LListString();
   list_assign->insert(0, "0");
   list_assign->insert(1, "1");
   list_assign->insert(2, "2");

   cout<<"pre assignment values"<<endl;
   cout<<"0th  "<<list_assign->get(0)<<endl;
   cout<<"1st  "<<list_assign->get(1)<<endl;
   cout<<"2nd  "<<list_assign->get(2)<<endl;

   cout<<"post assignment"<<endl;
   list_assign = list_copy;
   cout<<"0th  "<<list_assign->get(0)<<endl;
   cout<<"1st  "<<list_assign->get(1)<<endl;
   cout<<"2nd  "<<list_assign->get(2)<<endl;
*/
//########################################

  // Clean up memory.
  list->clear();
  list_copy->clear();
  list_assign->clear();
  delete list;
  delete list_copy;//copy constructor
  delete list_assign;//assignment tester
}