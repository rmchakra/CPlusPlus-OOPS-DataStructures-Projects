#ifndef __HASH_TABLE_H
#define __HASH_TABLE_H

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

using std::vector;
using std::pow;
using std::cout;
using std::endl;
using std::pair;
using std::make_pair;
using std::string;
using std::stringstream;
//questions
/*
	resize seg faults
	vector of pairs. The first will be unitialised string which 
	make_pair(-2, -1)
	string, int
	uninitialised string means the string is not present in the array.
	ints are initialised to 0; strings are initialised to null
	while(!string.empty())




	int main() {
    std::ofstream output("long_ass_file.txt");
    for (int i = 0; i < BIG_NUM; i++) { 
        std::ifstream input("book.txt");
       std::string curr;
        while (getline(input, curr)) 
            output << curr << std::ends;
        }
   }
   return 0;
}
    
}

Report all should output to the stream it takes by reference, not cout


*/

/**
* A Hashtable to store <std::string, int> as the entries. The string represents
* the element in the Hashtable, and the int represents the number of instances of
* that string in the Hashtable. 
*/
class my_int 
{
public:
	// Constructor/destructor
	my_int(int input_val = 0)
	{
		val = input_val;
	}
	int val;
};





class Hashtable
{
public:
	/**
	* Creates a new Hashtable instance. Two optional parameters are provided, and by
	* default are turned off. If the debug parameter is set to true, then the Hashtable
	* should use the pre-prescribed random numbers in the assignment description. The 
	* probing parameter will always be 0, 1, or 2, indicating the kind of collision
	* avoidance strategy. 
	* 0: Linear probing
	* 1: Quadratic probing
	* 2: Double hashing
	*/
	Hashtable(bool debug = false, unsigned int probing = 0);

	/**
	* Destructor.
	*/
	~Hashtable();

	/**
	* If the parameter k already exists as an element in the Hashtable, increment the 
	* total number of entries. Otherwise create a new entry with a count of 1.
	*/
	void add(const std::string& k);

	/**
	* Returns the total number of entries for the given string, or 0 if it does not
	* exist in the Hashtable.
	*/
	int count(const std::string& k) const;

	/**
	* Outputs to the provided stream every key-value pair of elements in the Hashtable
	* in the order they appear. The output should follow the format that each
	* key-value pair is printed on a separate line, and the key is separated from the 
	* value by a space .
	*/
	void reportAll(std::ostream& out) const;

private:
	/**
	* A helper function to resize and rehash the entries in the table when the load 
	* factor is >= 0.5. See the assignment description for the specific increments
	* when increasing the size of the Hashtable as well as other implementation details. 
	*/
	void resize();

	void add_helper(const std::string& k, vector <pair<string,int>>& hash_values_var);

	void insert_test()
	{
		int pos = 0;
			((hash_values[pos]).second) = 1;
			++((hash_values[pos]).second);//updating the int associated with it
				
	}

	/**
	* The actual hash function that transforms the string input into the index where
	* the element should be stored. See the assignment for more details on how to 
	* implement this function according to our specific guidelines. 
	*/
	int hash(const std::string& k) const;

private:
	/**
	* Include any additional private data members and/or helper functions to finish
	* this problem. 
    */

	void pos_finder(const std::string& k, int& pos, bool& already_present,const vector <pair<string,int>>& hash_v) const;
	int hash_func1(const std::string& k)const;
	int hash_func2(const std::string& k)const;	
	void word_gen(int (&a) [5], const std::string& k) const;


    //variabes
    unsigned int probe_type;
    vector <pair<string,int>> hash_values; 
    // vector <pair<string,int>> a;
    int unique_inserts;
    int no_of_resizes;
    bool debug_mode;
};

#endif