#include <iostream>
#include <fstream>
#include <sstream>
#include "avlbst.h"
#include <map>

#define MAX_FLOOR 9223372036854775807


using namespace std;

class floor_range
{

  public:

  floor_range(long long bot, long long top)
  {
    lower = bot; upper = top;
  }
  //< is this->top < rhs.bot

  long long get_lower()
  {
    return lower;
  }


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
    //if its neither greater nor less than then it must be equal
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
  
  // AVLTree <floor_range, string> myAVL;

  map<floor_range,string> my_obj;


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
      //return color if its there. Otherwise return white
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

           output << "Error - incorrect command" << endl;
        }
        else if ( ss>>extra_arg_checker) 
        {
           output << "Error - incorrect command" << endl;
        }
        else {//HERE Y0U ACTUALLY CARRY OUT THE THING
        //         

              

              map<floor_range,string>::iterator it = my_obj.find(floor_range(x, x));
              if(it == my_obj.end()){cout<<"WHITE \n";}
              else
              {
                //(*it).second when using my actual avltree
                cout<<it->second;
              }




             }
     }
     else if (command == "RECOLOR")
     {//RECOLOR x y c changes the color of the floors x through y (inclusive) to c. 
      //If y is less than x, then you should output an error.

        long long lower_recolor,upper_recolor;
        string c;
        ss >> lower_recolor;
        ss >> upper_recolor;
        ss >> c;

        string extra_arg_checker;

        if(ss.fail())
        {
           output << "Error - incorrect command" << endl;
        }

        else if(lower_recolor<1 || lower_recolor> MAX_FLOOR || upper_recolor<lower_recolor)
        {
           output << "Error - incorrect command" << endl;
        }


        else if (ss>>extra_arg_checker)
        {
           output << "Error - incorrect command" << endl;
        }
        else
        {
        //HERE IS THE VALID RECOLOR COMMAND   

          /*
            Starting from the root, look for input range [x,z].
If you find a range [i,j] that partially overlaps with the input range, then modify the node to have no overlap with the input range. If i < z, then update the range to [z+1, j]. Else, if x < j, then update the range to [i, x-1].
If you find a range that is fully contained within the input range, that is, x <= i <= j <= z, then delete the node.
If you find a range that fully contains the input range, that is, i <= x <= z <= j, then update the range to [i, x-1], and then add the node [z+1, j].
Finally add the node [x,z].

          */
            

        
          floor_range recolor_range(lower_recolor, upper_recolor);
          for (map<floor_range,string>::iterator found_node_it = my_obj.find(recolor_range);found_node_it!=my_obj.end(); found_node_it = my_obj.find(recolor_range))
          {//(*found_node_it).first gives the range key
            //  long long lower;
           // long long upper;


            //cant edit a key. NEed to remove and reinsert
            if((*found_node_it).first.lower < recolor_range.lower)
            {
              if ((*found_node_it).first.upper < recolor_range.upper)
              {
                
                string color = (found_node_it)->second;
                long long low;
                low = (found_node_it)->first).get_lower();

                // ((found_node_it)->first).upper = recolor_range.lower - 1;
              }
              else
              {
                string color = (*found_node_it).second;
                my_obj.insert(std::make_pair(floor_range l_n((*found_node_it).first.lower, lower_recolor-1), color));
                // my_obj.insert(std::make_pair(floor_range l_n((*found_node_it).first.lower, lower_recolor-1), color));
              
              }
            }
            else
            {
              if (/* condition */)
              {
                /* code */
              }
              else
              {

              }
            }

            


            my_obj.erase((*found_node_it).first);
          }

          //at the end insert the node for the found node after the while loop where you have made all the adjustments



            // while(it!= my_obj.end())

            //keep while looping to search and remove everything that falls within that range and .
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
