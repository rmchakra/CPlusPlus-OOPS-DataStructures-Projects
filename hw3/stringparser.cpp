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
#include <string>

using namespace std;

void remove_spaces(string& expression)
//TESTED
{ // remove spaces from string expression
	stringstream ss(expression);
	expression.clear();
	string temp; 
	while (ss >> temp) //>>skips over white spaces
	{expression+=temp;}
}
string minus_string(string a, string b)
{//TESTED
	std::string::size_type n;
	n = a.find(b);
	if (n == std::string::npos)return a;//b is not present in a
	return a.erase(n, b.size());
}

bool invalid_input(string &expression)
//TESTED
{ //checks for invalid characters or unmatched brackets
	int unmatched_brace_counter = 0;
	int brace_flag=0;
	int plus_or_minus_flag=0;
	for(unsigned int i = 0; i<expression.size(); i++)
	{ 
		if(unmatched_brace_counter<0)
		{//if more closing braces than open at any point in the expression
			return true;
		}

		char c = expression[i];

		if(c == '<' || c == '>' || c == '+'|| c == '-')
		{//valid operation characters
			// if(i<expression.size()-1)
			// {
			// 	if(expression[i+1]==')')
			// 	{
			// 		return true;
			// 	}
			// }
			if(c=='+'||c=='-')plus_or_minus_flag++;
			continue;//skips to next iteration so invalid_characters_present is not set to true
		}
		if(c == '(')
		{
			unmatched_brace_counter++;
			brace_flag++;
			continue;
		}
		if(c == ')')
		{
			unmatched_brace_counter--;
			brace_flag++;
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
	if(brace_flag ==0 && plus_or_minus_flag>0)
	{//no braces encountered and no + or - then add braces
		return true;

	}
	if(brace_flag ==0 && plus_or_minus_flag==0)
	{//no braces encountered and no + or - then add braces
		expression= "("+expression;
		expression+=")";

	}

	return false;
}

bool is_operator(string c)
{
	if(c=="<"||c==">"||c=="+"||c=="-")
	{
		return true;
	}
	return false;
}


void print_stack(stack<string> stack_main)
{
	while(!stack_main.empty())//while it has elements
	{//prints out the whole expression	
		cout<<stack_main.top()<<endl;
		stack_main.pop();
	}
}

bool is_string(string h)
{
	if( (!is_operator(h)) && h!="(" && h!=")")return true;
	return false;
}

bool expression_evaluator(string& expression, stack<string>& stack_main)
{//If malformed at any point simply return false to iterate to next expression
	//RETURNS STACK WITH JUST 1 ELEMENT WHICH IS RESULT
	//cout <<"HERE"<<endl;
	remove_spaces(expression);//removes the spaces from the expression
	if(invalid_input(expression))return false;//checks for invalid expression before any operation is performed
	stack<string> parenthesis_evaluator;

//############################################################################################
//From here onwards actual stack calculations begin expression is the whole linewise expression


//to remove from string is string.erase(pos,number of characters to erase)
// 	keep pushing onto stack 1
// if close bracket - pop from stack 1 and push onto stack 2 until open brace reached at top
// once open brace is reached in popping mode, pop it from the top
// evaluate stack 2
// push stack 2 result to top of stack 1
// if add and minus performed without braces then invalid expression add check for that eg a+b-c is invalid
	//add a clear function if malformed expression
	//void push(value_to_push), void pop() string top(), string.erase(pos,number of characters to erase)


	string current_string= "";//to add characters and store consequetive characters as strings
	while(expression!="")
	{//while there are still elements inside the original expression
		string current_char ="";
		current_char += expression[0];
		expression.erase(0,1);//removing the 0th element of the string after pushing onto the stack		

		if(current_char>="a"&& current_char<="z")
		{
			current_string += current_char;//adding the letters
			continue;//move onto next character of expression
		}

//############################################################################################
		//AN OPERATION HAS BEEN ENCOUNTERED
		if(current_string!="")
		{//current string is not empty i.e.e characters saved on it
			stack_main.push(current_string);//the string is now pushed onto the stack
			//current_string.clear();	
		}

		if(current_char!=")")
		{//any operation except close brace is simply pushed onto stack
			//before pushing onto the stack simply deal with the <>
			stack_main.push(current_char);
			 //print_stack(stack_main);
		}
		else//close brace has been encountered. remember just strings also I have added braces onto
		{//after this I need to have evaluator pushed onto main stack
			
			if(is_operator(  stack_main.top() ) )return false;//if proceeds from here second is a string
			//print_stack(stack_main);

			while(stack_main.top()!="(")
			{//keep moving backwards until opening brace is encountered, once encountered, will start moving forwards again
				
				parenthesis_evaluator.push(stack_main.top());//parenthesis evaluator now contains parenthis of main
				stack_main.pop();
			}
			;
			stack_main.pop();//remove "("
			//before a parenthesis has to be an operator, cant be a string
				//HERE IS MAIN STACK IS EMPTY
			if(!stack_main.empty())
			{if(  is_string(stack_main.top() ) )return false;//if it isnt an operator and not a "(" return false	
			}	//if theres only 1 bracket this would crash

			int back_remove_c=0, front_remove_c = 0, first_string_flag=0;
			string current_parenthesis_string ="";
			while(parenthesis_evaluator.size()>0)//contains everything except the braces
			{//current_parenthesis_string contains the result of the parenthesis and should be pushed onto main stack
				
				if(parenthesis_evaluator.top()=="<")//last character to be removed
				{
					back_remove_c++;
					parenthesis_evaluator.pop();
				}
				else if(parenthesis_evaluator.top()==">")//front character to be removed
				{
					front_remove_c++;
					parenthesis_evaluator.pop();
				}
				else if(parenthesis_evaluator.top()=="+")
				{
					if(front_remove_c>0 ||back_remove_c>0 || first_string_flag == 0)return false;//<> then + which is not possible
					parenthesis_evaluator.pop();
					if(is_string(parenthesis_evaluator.top()))
					{//if it is a string
						current_parenthesis_string+=parenthesis_evaluator.top();
						parenthesis_evaluator.pop();
					}
				}
				else if(parenthesis_evaluator.top()=="-")
				{
					if(front_remove_c>0 ||back_remove_c>0 )return false;//<> then - which is not possible
					parenthesis_evaluator.pop();
					if(is_string(parenthesis_evaluator.top()))
					current_parenthesis_string=minus_string(current_parenthesis_string,parenthesis_evaluator.top());
					parenthesis_evaluator.pop();
				}
				else
				{//it is a string
					if(first_string_flag == 0)
					{
						first_string_flag++;
						current_parenthesis_string = parenthesis_evaluator.top();
						parenthesis_evaluator.pop();
					}
					else
					{
						current_parenthesis_string.erase((current_parenthesis_string.size()-1-back_remove_c),back_remove_c);//removing the 0th element of the string after pushing onto the stack	
						back_remove_c = 0;
						current_parenthesis_string.erase(0,front_remove_c);//removing the 0th element of the string after pushing onto the stack	
						front_remove_c = 0;

					}	
				}
			
			}
			stack_main.push(current_parenthesis_string);
	    }//else brace
				
					
	}//while brace
			//stack_main.pop();//removes the opening brace
					
	return true;
}	  

int main(int argc, char* argv[])
{
  if(argc < 3){
    cerr << "Please provide an input and output file." << endl;
    return 1;
  }
  ifstream input(argv[1]);
  ofstream output(argv[2]);

 
  string expression;

  while(getline(input, expression)) 
  {//separating each line into expression

  	if(expression=="")
  	{//blank lines should be output as such
  		output << endl;
  		continue;
  	}

  	stack <string> stack_main;
  	if(expression_evaluator(expression, stack_main) ==false)
  	{
  		output <<"Malformed"<< endl;
		continue;
  	}

	//print_stack(stack_main);
  
  	output <<stack_main.top()<< endl;//printing out the result of the expression before going to next one
  	stack_main.pop();//emptying out the stack for the last iteration
  }
  return 0;
}
















				/*std::vector<string> v;
				for(int i =0; i<2;i++)
				{
					v.push_back(stack_main.top());
					stack_main.pop();
				}
				if(v[1]=="("){stack_main.push(v[0]); v.clear();}
				else if(v[1]=="<")//removes end
				{v[0].erase(v[0].size()-1,1);stack_main.push(v[0]); v.clear();}
				else if(v[1]==">")//removes start
				{v[0].erase(1,1);stack_main.push(v[0]); v.clear();}				
				if(is_operator(  stack_main.top() ) )return false;//if proceeds from here second is a string
				std::vector<string> v;
				for(int i =0; i<2;i++)
				{
					v.push_back(stack_main.top());
					stack_main.pop();
				}
				if(v[1]=="("){stack_main.push(v[0]); v.clear();}
				else if(v[1]=="<" || (v[1]==">"))//removes end
				{
					if(v[1]=="<" )
					{
						v[0].erase(v[0].size()-1,1);
					}
					else// >
					{
						v[0].erase(0,1);
					}
					
					while(stack_main.top()=="<" ||stack_main.top()=="<" )
					{
						if(stack_main.top()=="<")
						{
							v[0].erase(v[0].size()-1,1);
						}
						else
						{
							v[0].erase(0,1);
						}
						stack_main.pop();
					}
					stack_main.push(v[0]); v.clear();
				}
				else if(v[1]=="+"||v[1]=="-")
				{
					if(stack_main.top()=="("||stack_main.top()==")"||is_operator(stack_main.top()))return false;//malformed
					v.push_back(stack_main.top());//v[2]is string
					stack_main.pop();//remove that string from top
					


					//now first check if any prepend before it, if not then continue and need to actually perform that operation
					if(v[1]=="+")


*/
			
/*
string current_parenthesis_string = parenthesis_evaluator.top();
						current_parenthesis_string.erase((current_parenthesis_string.size()-back_remove_c),back_remove_c);//removing the 0th element of the string after pushing onto the stack	
						back_remove_c = 0;
						current_parenthesis_string.erase((current_parenthesis_string.size()-back_remove_c),back_remove_c);//removing the 0th element of the string after pushing onto the stack	
						back_remove_c = 0;
*/


	//Close brace operation encountered is this section - skip over this section for any other operation



		// if(current_char==")")//) is never added to the stack
		// {//if closing paranthesis encountered dont continue adding new elements but evaluate current ones from opening until that position 
		// 	cout<< stack_main.top()<<endl;
		// 	if(is_operator(stack_main.top()) )
		// 	{//this is malformed
		// 		return false;
		// 	}
		// }

		// 	string evaluated_expression_temp ="";
		// 	while(stack_main.top()!="(")
		// 	{//check situation where ( is encountered  whether unnecessary done
		// 		//
		// 		parenthesis_evaluator.push(stack_main.top());
		// 		stack_main.pop();//remove topmost
		// 		//parenthesis evaluator now contains the expression for the parenthesis
		// 	}
		// 	stack_main.pop();//removing opening brace
		// 	//parenthesis evaluator when you access will give commands in correct order



		// 	//clearing parenthesis_evaluator and performing operations
		// 	int front_remove_c =0, back_remove_c =0;//counts number of front and back characters to be removed
			



		// 	evaluated_expression_temp.clear();//emptying out the evaluated expression
		//AFTER SOLVING FOR THE EVALUATED EXPRESSION]


		// 		if(stack_main.top()=="")
		// 		current_char = stack_main.top();
		// 		parenthesis_evaluator.push(current_char);//pushing expression to be evaluated onto stack_evaluator
		// 		//open brace will be pushed onto evaluator as top but will be popped from stack_main
		// 		stack_main.pop();
		// 	}
		// 	stack_main.pop();//removing the "(" from the main stack for which the expression was evaluated


		// 	parenthesis_evaluator.pop();//popping the open brace from the stack_evaluator
		// 	//stack evaluator 
		// 	string evaluated_expression_temp="";//each evaluated expression within braces
		// 	while(parenthesis_evaluator.empty()==false)
		// 	{//while there are still elements inside stack evaluator
		// 		string top = parenthesis_evaluator.top();//topmost element of the parenthesis evaluator
		// 		parenthesis_evaluator.pop(); 
		// 		if(top!="-" && top!="<" && top!=">"&& top!="+")
		// 		{//if not an operation but a string
		// 			evaluated_expression_temp+=top;
		// 			continue;
		// 		}
		// 		if(top=="+")continue;//since acts the same way as though it were a single expression
				
		// 	}
		// 	stack_main.push(evaluated_expression_temp);
		// 	expression.erase(0,1);//removing the 0th element of the string after pushing onto the stack
		// 	continue;//so the code goes to the next character and doesnt act on the other operation
	 //}

