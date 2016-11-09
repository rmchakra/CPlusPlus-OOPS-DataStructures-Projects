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

#include "Scrabble_funcs.h"

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;

	int main (int nargs, char **args)
{
	if (nargs < 2 || nargs > 2)
		cout << "Usage: Scrabble <config-filename>\n";
	try {
		
		Game game(args[1]);

		// Good luck!

		int number_of_players;
		cout<<"Please enter the number of players (1-8): "<<endl;
		cin>>number_of_players;
		string dummy;//to clear the previous input
		getline(cin,dummy);

		for(int i = 0; i<number_of_players; i++)
		{
			string player_name;
			cout<<"Enter name of player " << i+1 << ":"<<endl;
			getline(cin,player_name); 

			cout<<endl;
			game.addPlayer (player_name);
		}

		while (!game.isFinished()) 
		{
			play(game);
		}
		gg_no_re(game);
		
	}
	catch (...)
	{ cout << "Fatal Error! "<< endl;
	return 1;}

	return 0;

}