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

}

void LListString::remove(int pos)
{
  // TODO: complete the remove function.

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

}
