#include <iostream>
#include <fstream>
#include <sstream>
#include "avlbst.h"

#define MAX_FLOOR 9223372036854775807


using namespace std;

class floor_range
{

  public:
    
  floor_range(long long b, long long t)
  {
    lower = b; upper = t;
  }
  //< is this->top < rhs.bot


  bool operator<(const floor_range& rhs) const;
  bool operator>(const floor_range& rhs) const;
  bool operator==(const floor_range& rhs) ;
  bool operator!=(const floor_range& rhs);

  long long lower;
  long long upper;
};

 bool floor_range::operator<(const floor_range& rhs) const
  {
    return (this->upper < rhs.lower);
  }
  bool floor_range::operator>(const floor_range& rhs) const
  {
    return (this->lower > rhs.upper);
  }
  bool floor_range::operator==(const floor_range& rhs)
  {//return true if theres any form of overlap
    return (    (    !((*this).operator<(rhs))   )    &&    (!((*this).operator<(rhs)) )      );
  }
  bool floor_range::operator!=(const floor_range& rhs)
  { 
    return(! ((*this).operator== (rhs)));
  }

//contains
  //partial less
  //partail greater
  //contained in


string make_upper(string a)
{
    string b = "";
    for(unsigned int i =0 ; i<a.size();i++)
    {
      
      b+=toupper(a[i]);
    }
   return b;
}


int main(int argc, char* argv[])
{
  
  AVLTree <floor_range, string> myAVL;

  if(argc < 3)
  {
    cerr << "Please provide an input and output file." << endl;
    return 1;
  }

  ifstream input(argv[1]);
  ofstream output(argv[2]);
  string command;

  while(getline(input, command)) 
  {
     stringstream ss;
     ss << command;
     ss >> command;

     command = make_upper(command);
     if (command == "COLOR" ) 
     {//x outputs the color of the skyscraper at height x.


        long long x;
        string c;
        ss >> x;
        ss >> c;

        string extra_arg_checker;//checks for extra arguments in line
        if(ss.fail())
        {//remember values start from 1 and not 0
           output << "Error - incorrect command" << endl;
        }

        else if(x<1 || x> MAX_FLOOR)
        {
          
           output << "Error - incorrect command" << endl
        }
        else if ( ss>>extra_arg_checker) 
        {
           output << "Error - incorrect command" << endl;
        }
        else {//HERE Y0U ACTUALLY CARRY OUT THE THING
        //         
             }
     }
     else if (command == "RECOLOR")
     {//RECOLOR x y c changes the color of the floors x through y (inclusive) to c. 
      //If y is less than x, then you should output an error.

        long long x,y;
        string c;
        ss >> x;
        ss >> y;
        ss >> c;

        string extra_arg_checker;

        if(ss.fail())
        {
           output << "Error - incorrect command" << endl;
        }

        else if(x<1 || x> MAX_FLOOR || y<x)
        {
           output << "Error - incorrect command" << endl;
        }


        else if (ss>>extra_arg_checker)
        {
           output << "Error - incorrect command" << endl;
        }
        else
        {
        //    
        }

     }
     else 
     {
        output << "Error - incorrect command" << endl;
     }
  }
 
  //FREE UP memory




  return 0;
}
