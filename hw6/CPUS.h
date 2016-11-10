#ifndef CPUS_H_
#define CPUS_H_

#include "AI_Base.h"


class CPUS: public AI_Base
{
 public:
Move getMove (const Board & board, const Player & player, std::map<char, int> initialTileCount);

};





#endif 