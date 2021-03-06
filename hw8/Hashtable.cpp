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
	// cout<<"debug mode is"<< debug_mode<<"probing is"<< probing<<"\n";
	no_of_resizes = -1;
	unique_inserts = 0;
	// cout<<"ENTERS CONSTRUCTOR";
	// int a;
	// cout<<"unitialised int is"<<a<<"\n";
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

// 	Just keep track of the number of insertions you've done
// And divide by size of the array/vector

	//but his is only for different insertions so first you search and see if its present. If it is then simply
	//increment the value of the int associated with the string 
	//if its not present, the hash function when fiuncding will give an index where the string is blank.
	//then you need to check for the resizing

	
	/**
	* If the parameter k already exists as an element in the Hashtable, increment the 
	* total number of entries. Otherwise create a new entry with a count of 1.
	*/

	double load_factor = ((double)unique_inserts/((double)hash_values.size()));
	if(load_factor >= 0.5)
	{
		// cout<<"BEFORE RESIZE \n";
		// cout<<"LOAD FACTOR:"<<return_load_factor();
		resize();

		// cout<<"AFTER RESIZE \n";
		// cout<<"LOAD FACTOR:"<<return_load_factor();
	}



	int pos; bool already_present;

	pos_finder(k, pos, already_present, hash_values);

	if(!already_present)
	{//if its a new value
		((hash_values[pos]).first) = k;
		unique_inserts++;
	}
	
	++((hash_values[pos]).second);//updating the int associated with it


	// load factor is number of keys/total buckets
	// resize when load factor is Greater than or equal to half
	


}

	/**
	* Returns the total number of entries for the given string, or 0 if it does not
	* exist in the Hashtable.
	*/
int Hashtable::count(const std::string& k) const
{

	// while()
	// {

	// }

	//dummy value
	int pos; bool already_present;

	pos_finder(k, pos, already_present, hash_values);

	if(already_present)
	{
		return ((hash_values[pos]).second);//returns the int associated with that string
	}
	else
	{
		return 0;
	}
}

	/**
	* Outputs to the provided stream every key-value pair of elements in the Hashtable
	* in the order they appear. The output should follow the format that each
	* key-value pair is printed on a separate line, and the key is separated from the 
	* value by a space .
	*/
void Hashtable::reportAll(std::ostream& out) const
{

	//if(string.empty()) means it is unitialised

	// out<<pair.first

		// cout<<"HASH VALUES 1234567890-W3E4567890-\n";
	for (unsigned int i = 0; i < hash_values.size(); ++i)
	{//change the i later
		if(   !(((hash_values[i]).first).empty())   )
		{//if string is not empty i.e. is a value
			out<<(hash_values[i]).first<<" "<<(hash_values[i]).second<<" "<<"\n";
			
			// cout<<(hash_values[i]).first<<" "<<(hash_values[i]).second<<"I IS:"<<i<<"\n";
		}
	}
}

	/**
	* A helper function to resize and rehash the entries in the table when the load 
	* factor is >= 0.5. See the assignment description for the specific increments
	* when increasing the size of the Hashtable as well as other implementation details. 
	*/


void Hashtable::resize()
{
	// cout<<"ENTERS RESIZE"<<"\n";
	int resize_array[] = {11, 23, 47, 97, 197, 397, 797, 1597, 3203, 6421, 12853, 25717, 51437, 102877, 205759, 411527, 823117, 1646237, 3292489, 6584983, 13169977, 26339969, 52679969, 105359969, 210719881, 421439783, 842879579, 1685759167};

	// resize_array.size();
	//simply create a new vector and then make the current vector equal to that


	// cout << no_of_resizes;
	no_of_resizes++;
	vector <pair<string,int>> new_hash_values(resize_array[no_of_resizes], make_pair("", 0));
	// cout<<"new_hash_values size is"<<new_hash_values.size()<<"WITH VALUES\n";

	for (unsigned int i = 0; i < hash_values.size(); ++i)
	{//transferring from hash to new_hash
		if(!(((hash_values[i]).first).empty()))
		{

			int pos; bool already_present;

			pos_finder(((hash_values[i]).first), pos, already_present, new_hash_values);

			((new_hash_values[pos]).first) = (hash_values[i]).first;
			((new_hash_values[pos]).second) = (hash_values[i]).second;

		}
		// cout<<new_hash_values[i].first<<" "<<new_hash_values[i].second<<"\n";
	}

	// hash_values.clear();
	hash_values.resize(resize_array[no_of_resizes]);
	hash_values = new_hash_values;


}

	/**
	* The actual hash function that transforms the string input into the index where
	* the element should be stored. See the assignment for more details on how to 
	* implement this function according to our specific guidelines. 
	*/
int Hashtable::hash(const std::string& k) const
{
	int pos; bool already_present;
	pos_finder(k,pos, already_present, hash_values);

	return pos;


	//get the int value

	/*

		First translate each letter into a value between 0 and 25, where a=0, b=1, c=2, ..., z=25. You can translate a string of 6 letters a1 a2 a3 a4 a5 a6 into an int via the following mathematical formula:
		265a1+264a2+263a3+262a4+26a5+a6

		Place zeros in the leading positions if your word is shorter than 6 letters.

If an input word is longer than 6 letters, then you should first do the above process for the last 6 letters in the word, then repeat the process for each successive 6 letters. You will never receive a word longer than "antidisestablishmentarianism" (that is, 28 letters), which should result in a sequence of no more than 5 ints

w1 w2 w3 w4 w5 where w5 was produed by the last 6 letters of the word.

Store these values in an int array. Place zeros in the leading positions if the word was shorter than 25 letters.

We will now hash the word. Use the following formula to produce the result, and make sure to cast this into a long long at the appropriate places so that you don't have an overflow error: the compiler will assume each intermediate value is an int if you don't specify this. size is the number of indices in the hashtable:
	*/

// 	(r1w1+r2w2+r3w3+r4w4+r5w5)%size = 
// (r1w1%size+r2w2%size+r3w3%size+r4w4%size+r5w5%size)%size
// If your hash is having messups from possible overfly




// 	Double Hashing
// This avoids both primary and secondary clumping.  You have a second hash function h'(k).
// If h(k) = i is taken, then try, in order, i + h0(k), i + 2 h0(k), i+ 3 h0(k), ...
// That is, h(k; i) = (h(k) + i h0(k))% m
	



//takes in the string and gives the input to store it at
}
	
void Hashtable::word_gen(int (&word_arr)[5], const std::string& k) const
{
	
//k is my string
	int w_arr_pos = 0;

	long long term_val = 0;
	int  counter = 0;

	for (int letter_pos =( k.size() -1); letter_pos > -1; counter++)
	{//goes backwards from last
		/* code */
	
		int letter_value =( k[letter_pos]) - 'a';//translating letter into an int an

		term_val+= (pow(26, counter) * letter_value);

		if(counter == 5)
		{//resetting the counter reached one sequence of 6 letters
			counter = -1;

			//each 6 letter sequence needs to be stores in separate pos of the int array
			//increase array index here.
			word_arr [w_arr_pos] = term_val;
			w_arr_pos++;
			term_val = 0;
		}

	--letter_pos;
	}
	word_arr [w_arr_pos] = term_val;
	for (int i = w_arr_pos+1; i < HASH_ARR_SIZE; ++i)
	{
		word_arr[i] = 0;
	}



//Word arr is never set
	//
	//




}

int Hashtable::hash_func1(const std::string& k, const vector <pair<string,int>>& hash_v) const
{

//beginning the function implementation
//my word array is reversed

	int word_arr [5];
	word_gen(word_arr, k);

	int random_numbers[] ={983132572, 1468777056, 552714139, 984953261, 261934300 };


/*
generating the random values r as coefficients for the arrauy

*/
	if(!debug_mode)
	{
		srand (time(NULL));//seeding the rand value
		for (int i = 0; i < HASH_ARR_SIZE; ++i)
		{
			random_numbers[i] = ((rand())%1685759167);
		}
	}

	for (int i = 0; i < HASH_ARR_SIZE; ++i)
	{
		random_numbers[i] = (random_numbers[i] % hash_v.size());
		word_arr[i] =( word_arr[i]% hash_v.size());
	}


	

	long long final_sum = 0;

	for (int i = 0; i < HASH_ARR_SIZE; ++i)
	{//cycles through the array until the desired position
		final_sum += (long long)(random_numbers[4 -i] * word_arr[i]);
	}

	//FINAL SUM IS 0
	// RANDOM NUMBERS GIVES 




	// cout<<"final_sum before mod is";

	final_sum = (final_sum% (hash_v.size()));



	//rbegin and rend
	//dummy value

	
	return (int)final_sum;


}
int Hashtable::hash_func2(const std::string& k) const
{

	int primes[]={7, 19, 43, 89, 193, 389, 787, 1583, 3191, 6397, 12841, 25703, 51431, 102871, 205721, 411503, 823051, 1646221, 3292463, 6584957, 13169963, 26339921, 52679927, 105359939, 210719881, 421439749, 842879563, 1685759113};

	// h(w)=p−((w1+w2+w3+w4+w5)%p).

	int word_arr [5];
	word_gen(word_arr, k);


	long long final_sum = 0;

	for (int i = 0; i < HASH_ARR_SIZE; ++i)
	{//cycles through the array until the desired position
		final_sum += (word_arr[i]);
	}

	final_sum = (final_sum% (primes[no_of_resizes]));
	int final_s = primes[no_of_resizes] - final_sum;



	//rbegin and rend
	//dummy value

	
	return final_s;
}



void Hashtable::pos_finder(const std::string& k, int& pos, bool& already_present,const vector <pair<string,int>>& hash_v) const
{//this gives position for both already present string as well as position to insert the new string at
	// the one that calls this helper function will do this code
	already_present = false;
	bool looped = false;
	if(probe_type == 0)
	{//linear
		//this should go into count
		for (pos = hash_func1(k, hash_v);   (!(((hash_v[pos]).first).empty())); )//while the position is occupied
		{

			if(		((hash_v[pos]).first)	== k	)
			{//already present

				// ++((hash_values[pos]).second);//updating the int associated with it
				already_present = true;
				break;
			}


			++pos;

			if(pos == (int)hash_v.size())
			{
				pos = 0;
				if(looped)
				{
					// cout<<" all positions are occupied - nowhere to insert string:"<<k<<"\n";
					// cout<<"size of hashtable is"<< hash_v.size()<<"\n";

					break;
				}
				looped = true;
			}

			
		}

	}
	else if(probe_type == 1)
	{//quadratic
		int j =1;
		for (pos = hash_func1(k, hash_v);   (!(((hash_v[pos]).first).empty())); j++)//while the position is occupied
		{

			if(		((hash_v[pos]).first)	== k	)
			{//already present

				// ++((hash_values[pos]).second);//updating the int associated with it
				already_present = true;
				break;
			}

			pos+= (j*j);
			pos = (pos%hash_v.size());

			// if(pos >= (int)hash_v.size())
			// {//This needs to be changed
			// 	pos = pos-(int)hash_v.size();
			// 	if(looped)
			// 	{
			// 		cout<<" all positions are occupied - nowhere to insert string:"<<k<<"\n";
			// 		cout<<"size of hashtable is"<< hash_v.size()<<"\n";
			// 		break;
			// 	}
			// 	looped = true;
			// }

			
		}
	}
	else
	{//probe_type must be 2
		//double hashing

		//i + h′(k), i + 2h′(k), i + 3h′(k), . .
		int j =1;
		int second_hash = hash_func2(k);
		int hash_size = hash_v.size();
		second_hash = second_hash%hash_size;
		
		for (pos = hash_func1(k, hash_v);   (!(((hash_v[pos]).first).empty())); j++)//while the position is occupied
		{
			// second_hash = hash_func2(k);
			//pos at the end of the loop is adjusted bu the multiplication but is only adjested for the max size after the looping conisition is checked

			if(		((hash_v[pos]).first)	== k	)
			{//already present

				// ++((hash_values[pos]).second);//updating the int associated with it
				already_present = true;
				break;
			}
			 pos+= (j*second_hash);
			 pos = (pos%hash_size);


			//  if(pos >= (int)hash_v.size())
			// {//This needs to be changed
			// 	pos = pos-(int)hash_v.size();
			// 	if(looped)
			// 	{
			// 		cout<<" all positions are occupied - nowhere to insert string:"<<k<<"\n";
			// 		cout<<"size of hashtable is"<< hash_v.size()<<"\n";
			// 		break;
			// 	}
			// 	looped = true;
			// }
			
		}

	}

}
