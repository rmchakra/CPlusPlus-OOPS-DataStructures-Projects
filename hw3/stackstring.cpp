#include "stackstring.h"

   StackString::StackString()
   {

   }
  StackString::~StackString()
  {

  }

  /**
   * Returns true if the stack is empty, false otherwise
   */

  bool StackString::empty() const
  {
  	return list.empty();
  }

  /**
   * Pushes a new value, val, onto the top of the stack
   */
  void StackString::push (const std::string& val)
  {
  	list.insert(0, val);
  }

  /**
   * Returns the top value on the stack.
   * If the stack is empty, the correct behavior is to throw
   * an exception: use LListString::get to achieve this.
   */
  std::string StackString::const & top () const
  {
  	return list.get(0);
  }

  /**
   * Removes the top element on the stack.
   * Should do nothing if the stack is empty.
   */
  void StackString::pop ()
  {
  	if(!list.empty())
  	list.remove(0);
  }

 private:
  /** 
   * Single data member of the Stack.
   * We use composition to implement this Stack 
   */
  LListString list;

