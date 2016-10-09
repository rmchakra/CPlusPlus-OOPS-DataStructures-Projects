/*
 * Dictionary.cpp
 *
 *  Created on: Sep 18, 2016
 *      Author: kempe
 */

// The following is a suggestion for how to proceed.
// Feel free to make any changes you like.

#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include "Dictionary.h"

using namespace std;

Dictionary::Dictionary (string dictionary_file_name)
{
	ifstream dictFile (dictionary_file_name.c_str());
	string word;

	if (dictFile.is_open())
	{
		while (getline (dictFile, word))
		{
		  //word.erase(word.length()-1); 
		  /* removes end-of-line character; 
		     uncomment if your dictionary file has Windows style line breaks */
			
			// What do you want to do with the word?
			word_list.push_back(word);
		
		}
		dictFile.close ();
	}
	else throw invalid_argument("Cannot open file: " + dictionary_file_name);
}

bool Dictionary::is_present(std::string word)
{//binary search
			int lo = 0, hi = word_list.size(), mid, char_pos;
			while(lo <= hi && char_pos<word_list.size()) 
			{
				char_pos=0;
				mid = (hi+lo)/2;

				if (word_list[mid]==word) return true;

				

				else if(word[char_pos] < word_list[mid][char_pos])
				hi = mid-1;

				else if(word[char_pos] > word_list[mid][char_pos])
				lo = mid+1;

				else if(  word_list[mid][char_pos]== word[char_pos])
				{
					while( (word_list[mid][char_pos]== word[char_pos]) &&  (char_pos<word.size()) )
					{
						
						if( (char_pos == word.size()-1) && (word_list[mid].size() > word.size())   )
							{hi = mid-1; break;}


							char_pos++;
					}

					if(word[char_pos] < word_list[mid][char_pos])
					hi = mid-1;

					else if(word[char_pos] > word_list[mid][char_pos])
					lo = mid+1;
				}
			}

			return false;
}