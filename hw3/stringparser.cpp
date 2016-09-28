/*
Task - 
read expressions consisting of strings and operations from a file,
 and evaluate and show the output of the given expression

Expressions
+(append the second string to the end of the first string)
 - (remove first instance of the second string from the first string),
 < (remove end character of string)
 > (remove start character of string) 
parentheses to specify a desired order of operations.

restrictions on input
string of 1 or more letters a-z (lower-case only)
Whitespace may occur in arbitrary places in string expressions, 
	but never in the middle of a string of letters
Each expression will be on a single line
string into ss
You will never produce the empty string
 string could contain arbitrary characters, arbitrary white space,

Working
take two parameters
	 the first being the input filename in which the formulas are stored,
  	second being the output filename
output
	each expression, your program should print to the output file, 
	one per line, one of the options:
		Malformed
	or	Result
	or  Blank lines (consisting of just white space, or nothing at all) are possible; for those, the correct output is also a blank line

For each expression
getline() and then parse the whole line of text that is returned to you.
DO NOT USE RECURSION
keep a stack on which you push pieces of formula.
Push open parenthesis '(', strings, and operators onto the stack. When you encounter a closing parenthesis ')', pop things from the stack and 
     evaluate them until you pop the open parenthesis '(. Check formatting (if incorrect exit with malformed)
     then push that result onto the stack as a string 

     USE STL STACK
Checking parenthetisization
if open bracket push onto stack1
continue pushing if anything except close
if next char is close keep pushing top onto another stack2 and pop present stack1 until open brace reached then just pop
evaluate popped expression and push result onto stack 
loop back 
evaluate from left to right since minus would make a different    


keep pushing onto stack 1
if close bracket - pop from stack 1 and push onto stack 2 until open brace reached at top
once open brace is reached in popping mode, pop it from the top
evaluate stack 2
push stack 2 result to top of stack 1

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <stack> 

using namespace std;

void remove_spaces(string& expression)
{ // remove spaces from string expression
	stringstream ss(expression);
	expression.clear();
	string temp; 
	while (ss >> temp) //>>skips over white spaces
	{expression+=temp;}
}
bool invalid_input(string expression)
{ //checks for invalid characters or unmatched brackets
	int unmatched_brace_counter = 0;
	for(unsigned int i = 0; i<expression.size(); i++)
	{ 
		if(unmatched_brace_counter<0)
		{//if more closing braces than open at any point in the expression
			return true;
		}

		char c = expression[i];

		if(c == '<' || c == '>' || c == '+'|| c == '-')
		{//valid operation characters
			continue;//skips to next iteration so invalid_characters_present is not set to true
		}
		if(c == '(')
		{
			unmatched_brace_counter++;
			continue;
		}
		if(c == ')')
		{
			unmatched_brace_counter--;
			continue;
		}
		if(c >='a' && c <= 'z')
		{//valid string characters as letters if not operation then can check range of letters
			continue;
		}
		return true;
		//if this statement is reached then invalid characters are present as otherwise it 
		//skips to next iteration through continue
	}
	if(unmatched_brace_counter!=0)
	{
	 //so if more open than closed
		return true;
	}
	return false;
}

int main(int argc, char* argv[])
{
  if(argc < 3){
    cerr << "Please provide an input and output file." << endl;
    return 1;
  }
  ifstream input(argv[1]);
  ofstream output(argv[2]);

 
  string expression, result ="";

  while(getline(input, expression)) 
  {//separating each line into expression

  	remove_spaces(expression);//removes the spaces from the expression

  	if(expression=="")
  	{//blank lines should be output as such
  		output << endl;
  		continue;
  	}
	
	if(invalid_input(expression))
	{	//checks for invalid expression before any operation is performed
		output <<"Malformed"<< endl;
		continue;//if invalid characters present expression not evaluated
	}

//############################################################################################
	//From here onwards actual stack calculations begin expression is the whole linewise expression
//to remove from string is string.erase(pos,number of characters to erase)
// 	keep pushing onto stack 1
// if close bracket - pop from stack 1 and push onto stack 2 until open brace reached at top
// once open brace is reached in popping mode, pop it from the top
// evaluate stack 2
// push stack 2 result to top of stack 1
	stack <string> stack_main, parenthesis_evaluator;//void push(value_to_push), void pop() string top(), string.erase(pos,number of characters to erase)

	while(expression!="")
	{//while there are still elements inside the evaluator
		char current_char = expression[0];//the current character on the expression
		if(current_char==')')
		{//if closing paranthesis encountered dont continue adding new elements but evaluate current ones
			while(current_char!="(")
			{//check situation where ( is encountered  whether unnecessary done
				current_char = stack_main.top();
				parenthesis_evaluator.push(current_char);//pushing expression to be evaluated onto stack_evaluator
				//open brace will be pushed onto evaluator as top but will be popped from stack_main
				stack_main.pop();
			}
			parenthesis_evaluator.pop();//popping the open brace from the stack_evaluator
			//stack evaluator 
			string evaluated_expression_temp="";//each evaluated expression within braces
			while(parenthesis_evaluator.empty()==false)
			{//while there are still elements inside stack evaluator
				char top = parenthesis_evaluator.top();//topmost element of the parenthesis evaluator
				parenthesis_evaluator.pop(); 
				if(top>=a && top<=z)
				{
					evaluated_expression_temp+=top;
				}
				if(top=='+')continue;//since acts the same way as though it were a single expression
				
			}
		}
		stack_main.push(current_char);
		string.erase(0,1);//removing the 0th element of the string after pushing onto the stack

	}

	stack_main.push();
	while(stack_main.empty()==false)
	{

		expression = stack_main.top();
		stack_main.pop();
	}

	  output <<expression<< endl;//printing out the result of the expression
  }

  return 0;
}