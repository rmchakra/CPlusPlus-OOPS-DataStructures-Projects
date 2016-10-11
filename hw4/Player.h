#ifndef PLAYER_H_
#define PLAYER_H_
#include "Tile.h"
#include "Bag.h"
#include <iostream>
#include "Board.h"
#include "Dictionary.h"


class Player {
public:
	Player (int handsize, Bag&);

	bool no_tiles();

	std::string return_name();
	void set_name(std::string name_input);

	int return_score();
	void set_score(int score_);

	void print_current_tiles();
	bool tiles_present(std::string letter);

 	void exchange_tiles(std::string tiles_2_B_Exchanged, Bag& bag);

 	bool valid_place( char dir, int s_row, int s_column, std::string tiles, Board board_obj, Dictionary& d);
 	//here board is passed by value not reference
 	
 	//void place( char dir, int s_row, int s_column, std::string tiles, Board& board)

 	
private:
	std::string name;
	int score; 
	std::set<Tile*> current_tiles;
};





#endif /* PLAYER_H_ */