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
#include "CPUS.h"
#include "CPUL.h"

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

		//AbstractAI** AIS;
		vector <AI_Base*> AIS;
		AIS.push_back (new CPUS());
		AIS.push_back (new CPUL());

		//AIS[0] = new CPUS();

		//AIS[1] = new CPUS();

		while (!game.isFinished()) 
		{
			play(game, AIS);
		}
		gg_no_re(game);
		delete AIS[0]; delete AIS[1]; //delete [] AIS;
		
	}
	catch(std::invalid_argument& inva) 
	{//if the arguments in the commandline is invalid
		cout  << "Fatal Error! " << inva.what() << endl; 

		return 1;
	} 
	catch(ConfigParameterException& cpe) 
	{
		string config_err_type = cpe.getMessage();
		cout  << "Config Parameter Exception" << config_err_type << endl;
		cout  << "The config file did not specify the following :-";
		if (config_err_type=="NUMBER")
		{ cout << "the number of tiles for a hand." << endl;}

		else if (config_err_type=="BOARD")
		 { cout << "a file to read the board from." << endl;}

		else if (config_err_type=="TILES") 
		{ cout << "a file to read the bag from." << endl;}

		else if (config_err_type=="DICTIONARY") 
		{cout << "a file to read the dictionary from." << endl;}


		return 1;
	} 
	catch (FileException& fe_obj) 
	{
		string File_Exception_type = fe_obj.getMessage();
		cout  << "File error! " << File_Exception_type << endl;
		if (File_Exception_type == "CONFIG")
			{cout  << "The config file could not be opened";}
		else if (File_Exception_type == "BAG")
			{cout  << "The bag file could not be opened";}
		else if (File_Exception_type == "BOARD")
			{cout  << "The board file could not be opened";}
		else if (File_Exception_type == "BOARDCONTENT")
			{cout  << "The board file contained a wrong symbol";}
		else if (File_Exception_type == "INIT") 
			{cout  << "The initialization file could not be opened";}
		else if (File_Exception_type == "INITCONTENT") 
			{cout  << "The initialization file contained a wrong symbol";}
		else if (File_Exception_type == "DICTIONARY")
			{cout  << "The dictionary file ";}
		

		return 1;
	}	
	catch (...)
	{ cout << "UNKNOWN CATCH ALL ERROR "<< endl;
	return 1;}

	return 0;

}