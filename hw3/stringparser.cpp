/*
Task - 
read expressions consisting of strings and operations from a file,
 and evaluate and show the output of the given expression

Expressions
+(append the second string to the end of the first string)
, - (remove first instance of the second string from the first string),
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

*/