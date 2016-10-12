//#include "Scrabble.h"
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

//prototypes of functions

void readConfigFile (std::string config_file_name,
					 std::string & dictionary_file_name,
					 std::string & board_file_name,
					 std::string & bag_file_name,
					 unsigned int & hand_size);
void testing(Dictionary& dict, Board& board, Bag& bag,unsigned int & hand_size);
bool main_incorrect_command(Dictionary& dict, Board& board, Bag& bag,unsigned int & hand_size);
int main (int nargs, char **args);


void readConfigFile (std::string config_file_name,
					 std::string & dictionary_file_name,
					 std::string & board_file_name,
					 std::string & bag_file_name,
					 unsigned int & hand_size)
{
	std::ifstream configFile (config_file_name.c_str());
	std::string line;
    bool number = false, board = false, tiles = false, dictionary = false;

	if (!configFile.is_open())
		throw std::invalid_argument("Cannot open file: " + config_file_name);
	while (getline (configFile, line) )
	{
		std::stringstream ss (line);
		std::string parameter;
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
		throw std::invalid_argument("Hand size not specified in config file");
	if (!board)
		throw std::invalid_argument("Board file name not specified in config file");
	if (!tiles)
		throw std::invalid_argument("Bag file name not specified in config file");
	if (!dictionary)
		throw std::invalid_argument("Dictionary file name not specified in config file");
}

bool main_incorrect_command(Dictionary& dict, Board& board, Bag& bag,unsigned int & hand_size)
{//gameplay goes on in here and if incorrect command is entered then you return true from here

	//testing(dict,board, bag, hand_size);
	//first player will have to be set up with true first move and the rest as false
	
	vector<Player> players;
	//initial set up
	int number_of_players=0;
	std::cout<<"Please enter the number of players (1-8): ";
	std::cin>>number_of_players; std::cout<<std::endl;
	
	for(int i = 0; i<number_of_players; i++)
	{
		std::string player_name;
		std::cout<<"Enter name of player " << i << ":";
		getline(std::cin,player_name); 
		std::cout<<std::endl;
		Player p(hand_size, bag);
		players.push_back(p);
	}


	//loop for actual gameplay

	std::stringstream ss;

	bool allpassed = true;


	for(int i =0;getline(std::cin,ss);i++)
	{//game ends when

		//player runs out of letters when all tiles have already been taken from the bag
		//after every move check if a player has no tiles
		//check all passed
		if( (bag.tilesRemaining()==0 ) && players[i].return_current_handsize() == 0) break;//after the and there is conditions needed to be checked
	
			

		std::cout<<players[i].return_name()<< ", it's your move."<<std::endl;
		std::cout<<"Current Scores"<<std::endl;
		for(int i = 0; i<number_of_players; i++)
		{
			std::cout<<players[i].return_name() << ":";
			std::cout<<players[i].return_score()<<std::endl;
		}

		board.print();
		std::cout<<"To pass your turn, type PASS.


 
   
   
Your current tiles: [A, 1] [A, 1] [P, 3] [R, 1] [I, 1] [U, 1] [U, 1]"<<std::endl;
	
	std::cout<<"To discard tiles, type EXCHANGE, followed by a string of those tiles."<<std::endl;
	
	std::cout<<"To place a word, type PLACE, followed by the following:"<<std::endl;

	std::cout<<"       first, either a | or - for vertical/horizontal placement;"<<std::endl;
	std::cout<<"       second, the row (from the top), the column (from the left),"<<std::endl;
	
	std::cout<<"       third, a sequence of letters to place;"<<std::endl;
	
	std::cout<<"       to use a blank tile, type ? followed by the letter you want to use it for."<<std::endl;
	
	std::cout<<"current tiles of p are"<<std::endl;
	players[i].print_current_tiles();
	std::cout<<std::endl;

	std::string command;
	ss>>command;
	command = players[i].make_upper(command);


		if(i ==(players.size()-1) )
		{//reached the last player then goes to -1 state which is inremented at the end of the loop
			i=-1;
			if(allpassed == true) break;
		
		}
	}







	//assuming one player to test the exchange







	return false;//if everything goes smoothly and it reaches the end

}

void testing(Dictionary& dict, Board& board, Bag& bag,unsigned int & hand_size)
{
	

	 board.print();
	//std::cout<<"Tiles remaining in bag BEFORE giving to player"<<std::endl;
	//std::cout << bag.tilesRemaining ()<<std::endl;
	 Player p(hand_size, bag);

	//Player p2(hand_size, bag);

	// std::cout<<"Tiles remaining in bag AFTER giving to player = BEFORE-7"<<std::endl;
	// std::cout << bag.tilesRemaining ()<<std::endl;
	//std::cout<<"no tiles result:"<<p.no_tiles()<<std::endl;
	 std::cout<<"current tiles of p are"<<std::endl;
	 p.print_current_tiles();
	 std::cout<<std::endl;
	//std::cout<<"current tiles of p2 are"<<std::endl;
	//p2.print_current_tiles();
	//std::cout<<std::endl;
	//p.set_name("name");
	//std::cout<<"printing name which was set as name : "<<p.return_name()<< std::endl;
	// std::cout<<"Enter Tiles to be checked for presence and then exchanged"<< std::endl;
	 std::string letters;
	// std::cin>> letters;
	 std::vector <Tile*> tiles_seen;//bullshit vector
	// std::cout<<"Tiles are present? : "<<p.tiles_present(letters, tiles_seen)<<std::endl;;
	// std::cout<<"Tiles being exchanged now "<<std::endl;
	// p.exchange_tiles(letters, bag);
	// std::cout<<"current tiles are"<<std::endl;
	// p.print_current_tiles();
	// std::cout<<std::endl;
	// std::cout<<"Tiles after exchange in bag =93"<<std::endl;
	// std::cout << bag.tilesRemaining ()<<std::endl;


	//std::cout<<"enter tiles to be placed"<< std::endl;
	//std::cin >> letters;
	//checking place
	//std::cout<< "placement is" << p.valid_place( '-' , 8 , 8 , letters, board, dict, tiles_seen);
 	//add a bool for the first move where it must cover start square
 	//check bag draw when tiles not remaining in handsize
 	std::cout<<"placing ay"<< std::endl;



 	bool first_move = true;

 	std::cout<<std::endl;
 	p.place('-' , 8 , 7 , "AY", board, dict, bag, first_move);
 	first_move = false;
 	board.print();
 	std::cout <<"TILES remaining = 90 = " <<bag.tilesRemaining ()<<std::endl;
 	 p.print_current_tiles();
	 std::cout<<std::endl;


	 p.exchange_tiles("IEPQIY", bag);
	//std::cout<<"current tiles are"<<std::endl;
	p.print_current_tiles();
	std::cout<<std::endl;
	// std::cout<<"placing ds to form days valid"<< std::endl;

 	//std::cout<<std::endl;
	p.place('-' , 8 , 6 , "PED", board, dict, bag, first_move);
 	board.print();
 	std::cout <<"TILES remaining = 89 = " <<bag.tilesRemaining ()<<std::endl;
 	 p.print_current_tiles();
	 std::cout<<std::endl;

	 //CHECKING VERTICAL PLACEMENT

	 p.place('|' , 7 , 7 , "LW", board, dict, bag, first_move);
 	board.print();
 	std::cout <<"TILES remaining =" <<bag.tilesRemaining ()<<std::endl;
 	 p.print_current_tiles();
	 std::cout<<std::endl;


	 // p.place('-' , 7 , 9 , "PY", board, dict, bag, first_move);
 	// board.print();
 	// std::cout <<"TILES remaining = 88 = " <<bag.tilesRemaining ()<<std::endl;
 	//  p.print_current_tiles();
	 // std::cout<<std::endl;
}

int main (int nargs, char **args)
{
	if (nargs < 2 || nargs > 2)
		std::cout << "Usage: Scrabble <config-filename>\n";
	try {
		std::string dictionaryFileName, boardFileName, bagFileName;
		unsigned int numTiles;

		readConfigFile (args[1],
						dictionaryFileName, boardFileName, bagFileName,
						numTiles);

		Dictionary dict (dictionaryFileName);
		Board board (boardFileName);
		Bag bag (bagFileName, 10); // second argument is random seed

		// Good luck!

		if(main_incorrect_command (dict, board, bag, numTiles)  ) std::cout<<"incorrect_command";
		return 0;
	}
	catch (std::invalid_argument & e)
	{ std::cout << "Fatal Error! " << e.what(); }

	return 1;
}
