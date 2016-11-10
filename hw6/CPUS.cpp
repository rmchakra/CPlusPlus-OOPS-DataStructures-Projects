#include "CPUS.h"

Move CPUS::getMove (const Board & board, const Player & player, std::map<char, int> initialTileCount)
{
	Move m("PASS", player);
	cout<<"CPUS IS MAKING A MOVE"<<endl;
	return m;
}