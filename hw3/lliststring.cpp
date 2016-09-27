#include "lliststring.h"
#include <cstdlib>
#include <stdexcept> // See the comment directly below.
#include <iostream>
using namespace std;

/**
 * This implementation uses exceptions in both versions of 'get'. 
 * You do not need to change the if-statements that use exceptions, 
 * nor do you need to test for exceptions. 
 *
 * In case you are interested, you can find more information here:
 * http://www.cplusplus.com/doc/tutorial/exceptions/
 * 
 * We will cover exceptions later this semester. 
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
  if(pos<0 || pos>size_){return;}//invalid positions

  if(pos==0)
  {//if inserting at head or empty list
    Item* newElement = new Item (val, NULL, head_);
    head_ = newElement;
    if(head_->next != NULL)
    {//were not inserting to an empty list
          head_->next->prev = head_;
    }
  }
  
  else if(pos==size_)
  {//if inserting at tail.
  // else if since for size 1 head and tail are same
    //size_-1 is the last position
     Item* newElement = new Item (val, getNodeAt(size_-1), NULL);
     newElement->prev->next = newElement;
  }
  else
  {//if inserting in the middle of linked list
     Item *Nodeat = getNodeAt(pos);
     Item* newElement = new Item (val, Nodeat->prev, Nodeat);

    newElement->next->prev = newElement;
    newElement->prev->next = newElement;
  }
  size_++;
}
void LListString::remove(int pos)
{
  // TODO: complete the remove function.
  if(pos < 0 || pos > size_-1 || size_==0 ){return;}//invalid positions

 Item *Nodeat = getNodeAt(pos);
  if(pos==0)
    {//if removing head
      head_=head_->next;
      if(size_!=1)
      {//if list has items and the removed head wasnt the only item
        //in the list
      head_->prev = NULL;
      }
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
    size_--;
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
   Item* Nodeat = head_;
    for(int i = 0; i<pos; i++)
   {
     Nodeat = Nodeat->next;
   }
  return Nodeat;
}
//##########################################################

   /**
   * Copy constructor (deep copy)
   */
  LListString::LListString (const LListString& other)
  {
    //deep copy so you want to cycle through and copy each item
    //making a copy of items of other and placing into your class
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
    //clear();
    //if(other==NULL)return;//if constructing from empty
    
     for(int i =0; i<other.size();i++)
      {
       insert(i, other.get(i));
     }
   
  }

  /**
   * Assignment Operator (deep copy)
   */
   
  LListString& LListString::operator= (const LListString& other)
  {

    if(this == &other)return *this;//if assigning to itself which 
    //could cause issues after clearing

  this->clear();

    for(int i =0; i<other.size();i++)
    {
      this->insert(i, other.get(i));
    }

    return *this;

  }
  

  /**
   * Concatenation operator.  Returns a new list consisting of other appended to this.  Does not modify this.
   */

  
  LListString LListString::operator+ (const LListString& other) const
  {
        LListString lhs(*this);//creating deep copy of this
        int lhs_tail = lhs.size();
     for(int i =0; i<other.size();i++)
    {
      lhs.insert(lhs_tail+i, other.get(i));
    }

    return lhs;

  }

  /**
   * Access Operator
   */
  std::string const & LListString::operator[] (int pos) const
  {
    if(pos < 0 || pos >= size_) {
    throw std::invalid_argument("bad location");
  }
    return get(pos);
  }

   