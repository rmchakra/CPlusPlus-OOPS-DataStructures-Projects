/*
 * Board.h
 *
 *  Created on: Sep 18, 2016
 *      Author: kempe
 */

// The following is a suggestion for how to proceed.
// Feel free to make any changes you like.

#ifndef BOARD_H_
#define BOARD_H_

#include <string>
 #include <Tile.h>

class Board {
public:
	Board (std::string board_file_name);
	~Board();

	// What else will this need?
	void Board::print();
	std::string** get_board();
	void set_board(std::string** input_board);


private:
	int _x, _y;
	int _startx, _starty;

	// What else will this need?
	string** board;

};


#endif /* BOARD_H_ */
