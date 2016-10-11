#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <stdexcept>

//#include "Board.h"
#include "Dictionary.h"
#include "Player.h"
// #include "Tile.h"
// #include "Bag.h"

using namespace std;

void readConfigFile (string config_file_name,
					 string & dictionary_file_name,
					 string & board_file_name,
					 string & bag_file_name,
					 unsigned int & hand_size)
{
	ifstream configFile (config_file_name.c_str());
	string line;
    bool number = false, board = false, tiles = false, dictionary = false;

	if (!configFile.is_open())
		throw invalid_argument("Cannot open file: " + config_file_name);
	while (getline (configFile, line) )
	{
		stringstream ss (line);
		string parameter;
		ss >> parameter;
		if (parameter == "NUMBER:")
			{ ss >> hand_size; number = true; }
		else if (parameter == "BOARD:")
		    { ss >> board_file_name; board = true; }
		else if (parameter == "TILES:")
			{ ss >> bag_file_name; tiles = true; }
		else if (parameter == "DICTIONARY:")
			{ ss >> dictionary_file_name; dictionary = true; }
	}
	if (!number)
		throw invalid_argument("Hand size not specified in config file");
	if (!board)
		throw invalid_argument("Board file name not specified in config file");
	if (!tiles)
		throw invalid_argument("Bag file name not specified in config file");
	if (!dictionary)
		throw invalid_argument("Dictionary file name not specified in config file");
}

bool main_incorrect_command(Dictionary& dict)
{//gameplay goes on in here and if incorrect command is entered then you return true from here
//main_incorrect_command(Dictionary& dict, Board& board, Bag& bag)
	//board.print();
/*	
	vector<Player> players;
	//initial set up
	int number_of_players=0;
	cout<<"Please enter the number of players (1-8): ";
	cin>>number_of_players; cout<<endl;
	
	for(int i = 0; i<number_of_players; i++)
	{
		string player_name;
		cout<<"Enter name of player " << i << ":";
		getline(cin,player_name); 
		cout<<endl;//or this is getline(cin, player_name);
		//players.push_back()
	}

	bool engame = false;
	while(!endgame)
	{//player runs out of letters when all tiles have already been taken from the bag
		//after every move check if a player has no tiles
		

		if( (bag.tilesRemaining()==0 ) && ) engame = true; break;//after the and there is conditions needed to be checked
	}
	
*/
	return false;//if everything goes smoothly and it reaches the end

}

int main (int nargs, char **args)
{
	if (nargs < 2 || nargs > 2)
		cout << "Usage: Scrabble <config-filename>\n";
	try {
		string dictionaryFileName, boardFileName, bagFileName;
		unsigned int numTiles;

		readConfigFile (args[1],
						dictionaryFileName, boardFileName, bagFileName,
						numTiles);

		Dictionary dict (dictionaryFileName);
		Board board (boardFileName);
		Bag bag (bagFileName, 10); // second argument is random seed

		// Good luck!

		if(main_incorrect_command (dict) ) cout<<"incorrect_command";
		//if(main_incorrect_command (dict, board, bag)  ) cout<<"incorrect_command";
		return 0;
	}
	catch (invalid_argument & e)
	{ cout << "Fatal Error! " << e.what(); }

	return 1;
}
