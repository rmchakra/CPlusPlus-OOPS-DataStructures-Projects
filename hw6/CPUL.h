#ifndef CPUL_H_
#define CPUL_H_

#include "AI_Base.h"


class CPUL: public AI_Base
{
 public:
Move getMove (const Board & board, const Player & player, std::map<char, int> initialTileCount);

};





#endif 