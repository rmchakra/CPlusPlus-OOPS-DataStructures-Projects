#include "lliststring.h"
#include <cstdlib>
#include <stdexcept> // See the comment directly below.

/**
 * This implementation uses exceptions in both versions of 'get'. 
 * You do not need to change the if-statements that use exceptions, 
 * nor do you need to test for exceptions. 
 *
 * In case you are interested, you can find more information here:
 * http://www.cplusplus.com/doc/tutorial/exceptions/
 * 
 * We will cover exceptions later this semester. 

 doubly linked list complete insert, remove, getNodeAt 
 getNodeAt(return a pointer to the i-th node)

 Valid locations for insertion are 0 to SIZE 
 (where SIZE is the size of the list and indicates a value
should be added to the back of the list)
 
Valid locations for remove are 0 to SIZE-1.
invalid location should cause the function to simply return 
without modifying the list.

allocate one of your LListString items and 
make calls to insert() and remove() that will
exercise the various cases you've coded in the functions.

sample test program - testAddToEmptyList.cpp
 */

LListString::LListString()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

LListString::~LListString()
{
  clear();
}

bool LListString::empty() const
{
  return (size_ == 0);
}

int LListString::size() const
{
  return size_;
}

void LListString::insert(int pos, const std::string& val)
{
  // TODO: complete the insert function.
  if(pos<0 || pos>SIZE){return;}//invalid positions

   if(pos==0)
  {//if inserting at head
    Item* newElement = new Item (string val, NULL, head_);
    head_ = newElement;
    if(head_->next != NULL)
    {//were not inserting to an empty list
          head_->next->prev = head_;
    }
  }
  else if(pos==size_)
  {//if inserting at tail
     Item* newElement = new Item (string val, getNodeAt(pos), NULL);
     newElement->prev->next = newElement;
  }

  else
  {//if inserting in the middle of linked list
     Item *Nodeat = getNodeAt(pos);
     Item* newElement = new Item (string val, Nodeat->prev, Nodeat);

    newElement->next->prev = newElement;
    newElement->prev->next = newElement;
  }
 
}

void LListString::remove(int pos)
{
  // TODO: complete the remove function.
  if(pos < 0 || pos > size_-1){return;}//invalid positions
 Item *Nodeat = getNodeAt(pos);
  if(pos==0)
    {//if removing head
      head=head->next;
      head->prev = NULL;
    }
    else
    {
      Nodeat->prev->next = Nodeat->next;
    }
    if(Nodeat->next !=  NULL)
    {
      Nodeat->next->prev =  Nodeat->prev;
    }
    //unsure about delete statement
  delete Nodeat;

}

void LListString::set(int pos, const std::string& val)
{
  if(pos >= 0 && pos < size_) {
  	Item *temp = getNodeAt(pos);
    temp->val = val;	
  }
}

std::string& LListString::get(int pos)
{
  if(pos < 0 || pos >= size_) {
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(pos);
  return temp->val;
}

std::string const & LListString::get(int pos) const
{
  if(pos < 0 || pos >= size_) {
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(pos);
  return temp->val;
}

void LListString::clear()
{
  while(head_ != NULL) {
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

LListString::Item* LListString::getNodeAt(int pos) const
{
  // TODO: complete the getNodeAt function.
  if(pos>-1 && pos<size)
  {

   Item* Nodeat = head_;
    for(int i = 0; i<pos; i++)
   {
     Nodeat = Nodeat->next;
   }

  return Nodeat;
  }

}
