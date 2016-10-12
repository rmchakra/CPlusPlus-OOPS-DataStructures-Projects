/*
 * Board.cpp
 *
 *  Created on: Sep 18, 2016
 *      Author: kempe
 */

// The following is a suggestion for how to proceed.
// Feel free to make any changes you like.

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Board.h"

Board::Board (std::string board_file_name)
{
	std::ifstream boardFile (board_file_name.c_str());
	std::string row;

	_x = _y = _startx = _starty = 0; // to appease compiler
	if (!boardFile.is_open())
		throw std::invalid_argument("Cannot open file: " + board_file_name);
	getline (boardFile, row);
	std::stringstream s1 (row);
	s1 >> _x >> _y;
	getline (boardFile, row);
	std::stringstream s2 (row);
	s2 >> _startx >> _starty;
	_startx --; _starty --;  // coordinates from 0 in array

	// Anything else you need to initialize?
	//initializing board
	board = new std::string* [_x];
	for(int i = 0; i<_x; i++)
	{
		board[i] = new std::string [_y];
	}

	for (int i = 0 ; i < _y; ++ i)
	{//i is the row
		getline (boardFile, row);
		for (int j = 0; j < _x; ++ j)
		{//j is the column
			// Fill in the following based on how you store the board.
			if (i == _starty && j == _startx) {board[i][j] =".d*"; }
			else switch (row[j]) {
			case '.' : board[i][j]="...";
			break;
			case '2' : board[i][j] = ".2 ";
			break;//double letter
			case '3' : board[i][j] = ".3 ";
			break;//double letter
			case 'd' : board[i][j] = ".d ";
			break;//double word bonus
			case 't' : board[i][j] = ".t ";
			break;//triple word bonus
			default:
				std::string error = "Improper character in Board file: ";
				throw std::invalid_argument(error + row[j]);
			}
		}
	}
	boardFile.close ();
}

void Board::print()
{
	std::cout<<"LEGEND"<<std::endl;
	std::cout<<"... = empty tile"<<std::endl;
	std::cout<<".d*= start spot"<<std::endl;
	std::cout<<".2 = double letter"<<std::endl;
	std::cout<<".3 = triple letter"<<std::endl;
	std::cout<<".d = double word"<<std::endl;
	std::cout<<".t = triple word"<<std::endl;


	std::cout<<std::endl;
	std::cout<<"BOARD"<<std::endl;
	
	for(int i =0; i<=_y;++i)
	{
		if(i<10) std::cout<<i << "   ";//if single digit occupies only 1 char but 2 digits occupy 2
		else std::cout<<i << "  ";//one space less for allignment
	}

	std::cout<<std::endl;
	
	for (int i = 0 ; i < _y; ++ i)
	{
		if(i<9) std::cout<<i+1<<"  ";
		else std::cout<<i+1<<" ";

		for (int j = 0; j < _x; ++ j)
		{
			std::cout<<board[i][j] << " ";
		}
		std::cout<<std::endl;
	}
}

std::string** Board::get_board()
{
	return board;
}

int Board::get_start_row()
{
	return _startx;
}

int Board::get_start_column()
{
	return _starty;
}
void Board::set_board(std::string** input_board)
{
	board = input_board;
}

int Board::get_width()
{
	return _x;
}
int Board::get_height()
{
	return _y;
}

Board::~Board()
{
	for(int i = 0; i<_x; i++)
	{
		delete[] board[i];
	}
	delete[] board;
}
