#include "stackstringstring.h"

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

  }

  /**
   * Pushes a new value, val, onto the top of the stack
   */
  void StackString::push (const std::string& val)
  {

  }

  /**
   * Returns the top value on the stack.
   * If the stack is empty, the correct behavior is to throw
   * an exception: use LListString::get to achieve this.
   */
  std::string StackString::const & top () const
  {

  }

  /**
   * Removes the top element on the stack.
   * Should do nothing if the stack is empty.
   */
  void StackString::pop ()
  {

  }

 private:
  /** 
   * Single data member of the Stack.
   * We use composition to implement this Stack 
   */
  LListString list;

