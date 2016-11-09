#ifndef Scrabble_funcs_H_
#define Scrabble_funcs_H_

#include "Game.h"
#include "Util.h"
#include <iostream>
#include "Exceptions.h"
#include <vector>
#include <sstream>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::vector;
using std::pair;
using std::stringstream;

void play(Game& game);
string scores_instruction_command(Game& game);
void gg_no_re(Game& game);//GOOD_GAME_NO_REMATCH
bool valid_move(Game& game, string command);


#endif