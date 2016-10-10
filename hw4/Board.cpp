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

using namespace std;

Board::Board (string board_file_name)
{
	ifstream boardFile (board_file_name.c_str());
	string row;

	_x = _y = _startx = _starty = 0; // to appease compiler
	if (!boardFile.is_open())
		throw invalid_argument("Cannot open file: " + board_file_name);
	getline (boardFile, row);
	stringstream s1 (row);
	s1 >> _x >> _y;
	getline (boardFile, row);
	stringstream s2 (row);
	s2 >> _startx >> _starty;
	_startx --; _starty --;  // coordinates from 0 in array

	// Anything else you need to initialize?
	//initializing board
	board = new string* [_x];
	for(int i = 0; i<_x; i++)
	{
		board[i] = new string [_y];
	}

	for (int i = 0 ; i < _y; ++ i)
	{//i is the row
		getline (boardFile, row);
		for (int j = 0; j < _x; ++ j)
		{//j is the column
			// Fill in the following based on how you store the board.
			if (i == _starty && j == _startx) {board[i][j]).useAs ('S'); }
			else switch (row[j]) {
			case '.' : board[i][j]="..";
			break;
			case '2' : [board[i][j] = ".2";
			break;//double letter
			case '3' : board[i][j] = ".3";
			break;//double letter
			case 'd' : board[i][j] = ".d";
			break;//double word bonus
			case 't' : board[i][j] = ".t";
			break;//triple word bonus
			default:
				string error = "Improper character in Board file: ";
				throw invalid_argument(error + row[j]);
			}
		}
	}
	boardFile.close ();
}

void Board::print()
{
	for(int i =0; i<_y;++i)
	{
		cout<<i;
	}

	cout<<endl;
	
	for (int i = 0 ; i < _y; ++ i)
	{
		cout<<i+1<< " ";
		for (int j = 0; j < _x; ++ j)
		{
			cout<<board[i][j];
		}
		cout<<endl;
	}
}

std::string** get_board()
{
	return board;
}


void set_board(std::string** input_board)
{
	board = input_board;
}

Board::~Board()
{
	for(int i = 0; i<_x+1; i++)
	{
		delete[] a[i];
	}
	delete[] a;
}
