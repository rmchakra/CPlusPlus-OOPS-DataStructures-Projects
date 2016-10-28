/*
 * Dictionary.h
 *
 *  Created on: Sep 18, 2016
 *      Author: kempe
 */

// The following is a suggestion for how to proceed.
// Feel free to make any changes you like.

#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include <string>
#include <set>
#include <fstream>
#include <iostream>
#include <stdexcept>

class Dictionary {
public:
	Dictionary (std::string dictionary_file_name);
	//is_present_bin_search(std::string word);
	bool is_present(std::string word);

	// what else will this need?
private:
	//std::vector<string> word_list;
	std::set<std::string> dict;
};


#endif /* DICTIONARY_H_ */
