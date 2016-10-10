#ifndef PLAYER_H_
#define PLAYER_H_
#include <"Tile.h">
#include <"Bag.h">
#include <iostream>
#include <"Board.h">
#include <"Dictionary.h">


class Player {
public:
	Player ();

	bool no_tiles();

	std::string return_name();
	void set_name(std::string name_input);

	std::string return_score();
	void set_score(int score_);

	void print_current_tiles();
	bool tiles_present(std::string tiles);

 	void exchange_tiles(std::string tiles_2_B_Exchanged, Bag& bag);

 	bool Player::place( char dir, int row, int column, std::string tiles, Board& board);//works on actual board

 	bool Player::valid_place( char dir, int row, int column, std::string tiles, Board board);//works on copy of board

private:
	string name;
	int score; 
	std::set<Tile*> current_tiles;
};





#endif /* PLAYER_H_ */