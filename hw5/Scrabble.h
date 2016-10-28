#ifndef Scrabble_H_
#define Scrabble_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <stdexcept>

#include "Board.h"
#include "Dictionary.h"
#include "Player.h"
#include "Tile.h"
#include "Bag.h"


class Scrabble {
public:
	Scrabble();

	void readConfigFile (std::string config_file_name,
					 std::string & dictionary_file_name,
					 std::string & board_file_name,
					 std::string & bag_file_name,
					 unsigned int & hand_size);
	bool main_incorrect_command(Dictionary& dict, Board& board, Bag& bag,unsigned int & hand_size);
	void testing(Dictionary& dict, Board& board, Bag& bag,unsigned int & hand_size);
	int  main (int nargs, char **args);


 	
private:
	

};




#endif /* Scrabble_H_ */