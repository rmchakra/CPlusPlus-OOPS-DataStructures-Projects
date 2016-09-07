#include <iostream>
#include <sstream>
#include <cstring> 
#include <fstream>

using namespace std;

int main (int argc, char* argv[])
{
  ifstream infile (argv[1]);
  int size;
  infile >> size;
  string* words = new string [size];
  
  for(int i = 0; i<size; i++ )
  {

     infile >> words[i];
  }
for(int i = size-1; i>-1 ; i--)
{
   cout << words[i]<<endl;
}

delete [] words;  
  return 0;
}
