#include "Hashtable.h"


#define DUMMY 5
#define HASH_ARR_SIZE 5
#define INITIAL_HASH_ELEMENT_COUNT 11
/**
* A Hashtable to store <std::string, int> as the entries. The string represents
* the element in the Hashtable, and the int represents the number of instances of
* that string in the Hashtable. 
*/

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
Hashtable::Hashtable(bool debug, unsigned int probing)
{
	probe_type = probing;
	debug_mode = debug;
	resize();

	// for (int i = 0; i < INITIAL_HASH_ELEMENT_COUNT; ++i)
	// {
	// 	hash_values.push_back(my_int(0));
	// }
}

	/**
	* Destructor.
	*/
Hashtable::~Hashtable()
{

}

	/**
	* If the parameter k already exists as an element in the Hashtable, increment the 
	* total number of entries. Otherwise create a new entry with a count of 1.
	*/
void Hashtable::add(const std::string& k)
{//your hash function converts the string to an index in the int array which gives the number of times that element is there

	// probe_type = 0 means linear probing, 1 means quadratic probing, and 2 means double hashing.
}

	/**
	* Returns the total number of entries for the given string, or 0 if it does not
	* exist in the Hashtable.
	*/
int Hashtable::count(const std::string& k) const
{

	//dummy value
	return DUMMY;
}

	/**
	* Outputs to the provided stream every key-value pair of elements in the Hashtable
	* in the order they appear. The output should follow the format that each
	* key-value pair is printed on a separate line, and the key is separated from the 
	* value by a space .
	*/
void Hashtable::reportAll(std::ostream& out) const
{

}

	/**
	* A helper function to resize and rehash the entries in the table when the load 
	* factor is >= 0.5. See the assignment description for the specific increments
	* when increasing the size of the Hashtable as well as other implementation details. 
	*/
void Hashtable::resize()
{
	int resize_array[] = {11, 23, 47, 97, 197, 397, 797, 1597, 3203, 6421, 12853, 25717, 51437, 102877, 205759, 411527, 823117, 1646237, 3292489, 6584983, 13169977, 26339969, 52679969, 105359969, 210719881, 421439783, 842879579, 1685759167};

	hash_values.resize(resize_array[no_of_resizes]);
	no_of_resizes++;

}

	/**
	* The actual hash function that transforms the string input into the index where
	* the element should be stored. See the assignment for more details on how to 
	* implement this function according to our specific guidelines. 
	*/
int Hashtable::hash(const std::string& k) const
{
	/*

		First translate each letter into a value between 0 and 25, where a=0, b=1, c=2, ..., z=25. You can translate a string of 6 letters a1 a2 a3 a4 a5 a6 into an int via the following mathematical formula:
		265a1+264a2+263a3+262a4+26a5+a6

		Place zeros in the leading positions if your word is shorter than 6 letters.

If an input word is longer than 6 letters, then you should first do the above process for the last 6 letters in the word, then repeat the process for each successive 6 letters. You will never receive a word longer than "antidisestablishmentarianism" (that is, 28 letters), which should result in a sequence of no more than 5 ints

w1 w2 w3 w4 w5 where w5 was produed by the last 6 letters of the word.

Store these values in an int array. Place zeros in the leading positions if the word was shorter than 25 letters.

We will now hash the word. Use the following formula to produce the result, and make sure to cast this into a long long at the appropriate places so that you don't have an overflow error: the compiler will assume each intermediate value is an int if you don't specify this. size is the number of indices in the hashtable:
	*/


	
	return DUMMY;
}

int Hashtable::hash_func1(const std::string& k)
{
	int random_numbers[] ={983132572, 1468777056, 552714139, 984953261, 261934300 };

/*
generating the random values r as coefficients for the arrauy

*/

if(!debug_mode)
{
	srand (time(NULL));//seeding the rand value
	for (int i = 0; i < HASH_ARR_SIZE; ++i)
	{
		random_numbers[i] = rand();
	}
}



//beginning the function implementation




	int w_arr_pos = 0;
	int word_arr [5];

	int term_val = 0;

	for (int letter_pos =( k.size() -1), counter = 0; letter_pos > -1; --letter_pos, counter++)
	{//goes backwards from last
		/* code */
	
		int letter_value =( k[letter_pos]) - 'a';//translating letter into an int an

		term_val+=pow(26, counter);

		if(counter == 5)
		{//resetting the counter reached one sequence of 6 letters
			counter = -1;

			//each 6 letter sequence needs to be stores in separate pos of the int array
			//increase array index here.
			word_arr [w_arr_pos] = term_val;
			w_arr_pos++;
			term_val = 0;
		}
	}
	for (int i = w_arr_pos+1; i < HASH_ARR_SIZE; ++i)
	{
		word_arr[i] = 0;
	}

	long long final_sum = 0;

	for (int i = 0; i < HASH_ARR_SIZE; ++i)
	{//cycles through the array until the desired position
		final_sum += (long long)(random_numbers[i] * word_arr[i]);
	}

	final_sum = (final_sum% (hash_values.size()));



	//rbegin and rend
	//dummy value
	
	
	return DUMMY;


}
int Hashtable::hash_func2(const std::string& k)
{

}
