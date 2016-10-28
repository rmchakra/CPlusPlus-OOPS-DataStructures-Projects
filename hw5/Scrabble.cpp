#include <NumberWindow.h>
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
	//add an ss.fail for each of the stringstream to anywhere
	//testing(dict,board, bag, hand_size);
	//first player will have to be set up with true first move and the rest as false
	//return true;





//COMMENT OUT TESTING AND THE RETURN STATEMENT TO SEE IF IT WORKS

	std::vector<Player> players;
	//initial set up
	int number_of_players=0;
	std::cout<<"Please enter the number of players (1-8): "<<std::endl;
	
	std::cin>>number_of_players;

	std::string dummy;//to clear the previous input
	getline(std::cin,dummy);
	
	for(int i = 0; i<number_of_players; i++)
	{
		std::string player_name;
		std::cout<<"Enter name of player " << i+1 << ":"<<std::endl;
		getline(std::cin,player_name); 

		std::cout<<std::endl;
		Player p(hand_size, bag);
		p.set_name(player_name);
		
		players.push_back(p);
	}


	//loop for actual gameplay

	//std::stringstream ss;
	std::string full_command;
	std::string command="";


	bool allpassed = true;
	bool first_move = true;
	int player_ref = 0;
	while(true)
	{//game ends when

		//player runs out of letters when all tiles have already been taken from the bag
		//after every move check if a player has no tiles
		//check all passed
		if( (bag.tilesRemaining()==0 ) && players[player_ref].return_current_handsize() == 0)
		{
				std::cout<<"ENDGAME: No tiles in bag and no tiles in hand"<<std::endl;
				break;//after the and there is conditions needed to be checked
		}	

		std::cout<<players[player_ref].return_name()<< ", it's your move."<<std::endl;
		std::cout<<"Current Scores"<<std::endl;
		for(int i = 0; i<number_of_players; i++)
		{
			std::cout<<players[i].return_name() << ":";
			std::cout<<players[i].return_score()<<std::endl;
		}

		board.print();
		std::cout<<"To pass your turn, type PASS"<<std::endl;
		std::cout<<"To discard tiles, type EXCHANGE, followed by a string of those tiles."<<std::endl;
	
		std::cout<<"To place a word, type PLACE, followed by the following:"<<std::endl;
		std::cout<<"       first, either a | or - for vertical/horizontal placement;"<<std::endl;
		std::cout<<"       second, the row (from the top), the column (from the left),"<<std::endl;
		std::cout<<"       third, a sequence of letters to place;"<<std::endl;
		std::cout<<"       to use a blank tile, type ? While the letter is being placed you will be prompted for the letter you wish to place"<<std::endl;
		std::cout<<"current tiles of"<<players[player_ref].return_name()<<"are:"<<std::endl;
		players[player_ref].print_current_tiles();
		std::cout<<std::endl;



		std::cout<<"ENTER COMMAND:"<<std::endl;
		getline(std::cin, full_command);//getting the command
		std::stringstream ss;
		ss<<full_command;
		std::cout<<"FULL COMMAND IS :"<<ss.str()<<std::endl;
		ss>>command;
		command = players[player_ref].make_upper(command);



		
		if(command == "EXCHANGE")
		{
			allpassed = false;
			std::string tiles_2_B_Exchanged;
			ss>>tiles_2_B_Exchanged;


			if(ss.fail())
			{
				std::cout<<"INCORRECT COMMAND - wrong number of inputs"<<std::endl;
				continue;
			}

			players[player_ref].exchange_tiles(tiles_2_B_Exchanged,bag);

		}
		else if(command == "PLACE")
		{
			allpassed = false;
			char dir;
			ss>>dir;
			if(ss.fail())
			{
				std::cout<<"INCORRECT COMMAND - wrong number of inputs"<<std::endl;
				continue;
			}
			if(dir!= '-' && dir!= '|'){std::cout<<"INCORRECT COMMAND wrong dir"<<std::endl; continue;}

			int  row, column;
			std::string letters_to_be_placed;

			ss>>row;
			ss>>column;
			ss>>letters_to_be_placed;

			if(ss.fail())
			{
				std::cout<<"INCORRECT COMMAND - wrong number of inputs"<<std::endl;
				continue;
			}
			letters_to_be_placed = players[player_ref].make_upper(letters_to_be_placed);

			// for(int i = 0; i< letters_to_be_placed.size(); i++)
			// {
			// 	if(letters_to_be_placed[i] == '?')
			// 	{
			// 			//std::cout<<"Enter use of tile"<<std::endl;
			//    			//char use;
			//    			//std::cin>>use;
			//    			curr_tile->useAs(toupper(use));
			// 	}
			// }

			players[player_ref].place( dir, row, column, letters_to_be_placed, board, dict, bag, first_move);
 	

			first_move = false;
		}
		else if(command != "PASS"){std::cout<<"INCORRECT COMMAND unrecognizable"<<std::endl; continue;}





		if(player_ref == ((int)players.size()-1)) 
		{//reached the last player then goes to -1 state which is incremented at the end of the loop
			if(allpassed == true)
			{std::cout<<"ENDGAME: All PASSED"<<std::endl; break;}
			
			player_ref=-1;
			allpassed = true;
			//resetting allpassed back to true
		}
		player_ref++;

	}








	//assuming one player to test the exchange







	return false;//if everything goes smoothly and it reaches the end

}
void testing(Dictionary& dict, Board& board, Bag& bag,unsigned int & hand_size)
{
	Player p(hand_size, bag);
	 std::vector <Tile*> tiles_seen;//bullshit vector
 	bool first_move = true;
 	std::cout<<std::endl;
 	p.place('-' , 8 , 8 , "day", board, dict, bag, first_move);
 	first_move = false;
 	p.place('-' , 7 , 9 , "py", board, dict, bag, first_move);
 	p.place('-' , 7 , 10 , "ale", board, dict, bag, first_move);
	p.place('-' , 7 , 13 , "sin", board, dict, bag, first_move);
 
 	std::cout<<"score 53 = "<<p.return_score()<<std::endl;

}







void testing_basic(Dictionary& dict, Board& board, Bag& bag,unsigned int & hand_size)
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
	bool result = main_incorrect_command (dict, board, bag, numTiles);
		return 0;
	}
	catch (std::invalid_argument & e)
	{ std::cout << "Fatal Error! " << e.what(); }

	return 1;
}
