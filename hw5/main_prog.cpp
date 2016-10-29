#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <stdexcept>

#include <QApplication>

#include "Board.h"
#include "Dictionary.h"
#include "Player.h"
#include "Tile.h"
#include "Bag.h"
#include "Sqt.h"
#include "NumberWindow.h"

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

int main (int nargs, char **args)
{
	if (nargs < 2 || nargs > 2)
		std::cout << "Usage: Scrabble <config-filename>\n";

	QApplication app(nargs, args);
	
	// int a_e_e =1;

	std::string dictionaryFileName, boardFileName, bagFileName;
	unsigned int numTiles;
	try {

		readConfigFile (args[1],
						dictionaryFileName, boardFileName, bagFileName,
						numTiles);

	//bool result = main_incorrect_command (dict, board, bag, numTiles);
		//return 0;
	}
	catch (/*std::Exception*/ .../*& e*/)
	{ std::cout << "Fatal Error! "<<std::endl; /*<< e.what()*/; return 1;}

	Dictionary dict (dictionaryFileName);
	Board board (boardFileName);
	Bag bag (bagFileName, 10); // second argument is random seed

	// Good luck!

	NumberWindow w[2];
  for(int i = 0; i<2;i++)
  {
  	w[i].set_window_number(i);
  } 
   w[0].show();

   	Sqt s(&app, board, dict, bag, numTiles);

   	//main function test will be placed in sqt later
   QObject::connect (&w[0], SIGNAL(W0(/*QString ,*/int )),&w[1],SLOT(W0confirmPressed (/*QString ,*/int)));
   //QObject::connect (&w[1], SIGNAL(W2send(QVector<QString> , int )),&w[2],SLOT(W1confirm(QVector<QString>, int )));
  QObject::connect (&w[1], SIGNAL(W2send(QVector<QString> , int )),&s,SLOT(setup(QVector<QString> , int )));//connecting 2nd and third window
  




	//std::string s = "board.txt"

	// s.show();
	return app.exec();

	// std::cout << "jkhdsfa" << std::endl;
	// return a_e_e;
}