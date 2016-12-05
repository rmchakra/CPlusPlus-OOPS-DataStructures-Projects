#include "Hashtable.h"
#include <ctime>

using namespace std;
void make_lower(string& a)
	{
		std::string b = "";
		for(unsigned int i =0 ; i<a.size();i++)
		{
			if(a[i]>'A' && a[i] < 'Z')
			{		
				b+=tolower(a[i]);
			}
			else
			{
				b+=a[i];
			}
		}
	}

int main ( int argc, char *argv[] )
{
	if(argc < 6)
  {
    cerr << "Please provide correct number of commandline args" << endl;
    return 1;
  }

  ifstream input(argv[1]);
  ofstream output(argv[2]);
  unsigned int probing; int debug_mo; bool debug; int program_repetitions;


  stringstream ss;
  ss<<argv[3];
  ss>> probing; ss.clear();
  ss<<argv[4];
  ss>>debug_mo; ss.clear();
 
  if(debug_mo == 0)
  {
  	debug = false;
  }	
  else
  {
  	debug = true;
  }
  ss<<argv[5];
  ss>> program_repetitions;

  Hashtable haha(debug,probing);

  string word;
  vector<string> word_list;
  while(input>>word)
  {
  	make_lower(word);
  	for (unsigned int i = 0; i < word.size(); ++i)
  	{
  		if(word[i] < 'a' || word[i]> 'z')
  		{
  			word.erase(i, 1);
  		}
  	}

  	word_list.push_back(word);

  	// output<<word<<"\n";
  }


  return 0;

    /*

./counting [input] [output] x d r

	x will be an integer with value 0, 1, or 2. If x=0, use linear probing. If x=1, use quadratic probing. If x=2, use double-hashing.
d will be an integer with value 0 or 1. If d=0, then create a normal HashTable. If d=1, then create a debug-mode HashTable.
r will be an integer that says how often to repeat the whole program. (This is useful to measure the time when the input is small and the time is otherwise reported as 0.)

  */




}