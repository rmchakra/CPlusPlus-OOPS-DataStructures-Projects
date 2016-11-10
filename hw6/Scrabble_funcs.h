#ifndef Scrabble_funcs_H_
#define Scrabble_funcs_H_

#include "Game.h"
#include "Player.h"
#include "Board.h"
#include "Util.h"
#include "AI_Base.h"
#include <iostream>
#include "Exceptions.h"
#include <vector>
#include <sstream>
#include <map>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::vector;
using std::pair;
using std::stringstream;

void play(Game& game, vector <AI_Base*> AIS);
string scores_instruction_command(Game& game);
void gg_no_re(Game& game);//GOOD_GAME_NO_REMATCH
bool valid_move(Game& game, string command);
void display_move(Game& game, Move& m);


#endif