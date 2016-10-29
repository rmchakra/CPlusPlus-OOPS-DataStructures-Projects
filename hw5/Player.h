#ifndef PLAYER_H_
#define PLAYER_H_
#include "Tile.h"
#include "Bag.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "Board.h"
#include "Dictionary.h"
#include <sstream>
#include <QApplication>
#include <QString>
#include <QObject>
#include <QPushButton>


class Player {
public:
	Player (int handsize, Bag&);

	std::string make_upper(std::string a);
	std::string make_lower(std::string a);

	bool no_tiles();

	std::string return_name();
	void set_name(std::string name_input);

	int return_score();
	void set_score(int score_);

 	int return_current_handsize();

	std::string return_str_current_tiles();
	bool tiles_present(std::string letters, std::vector <Tile*>& tiles_seen);

 	std::string exchange_tiles(std::string tiles_2_B_Exchanged, Bag& bag);
//"S" is returned for success or true and if it isnt S then it must be false

 	std::string valid_place( char dir, int s_row, int s_column, std::string tiles, Board& board_obj, Dictionary& d, std::vector <Tile*>& tiles_seen, bool first_move, int& move_score);
 	//add a bool for the first move where it must cover start square
 	//check bag draw when tiles not remaining in handsize
 	std::string place( char dir, int s_row, int s_column, std::string tiles, Board& board_obj, Dictionary& dict, Bag& bag, bool first_move, QPushButton ***pb_board);
 	int char_to_int(char c);
 	int word_multiplier_bonus(char c);
 	int letter_multiplier_bonus(char c);
 	
private:
	std::string name;
	int score; 
	std::set<Tile*> current_tiles;
	int max_handsize;

};





#endif /* PLAYER_H_ */