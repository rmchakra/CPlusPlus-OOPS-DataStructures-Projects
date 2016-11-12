#include "CPUL.h"

Move CPUL::getMove (const Board & board, const Player & player, std::map<char, int> initialTileCount)
{
	vector<Move> possible_moves; vector<int> possible_scores;

	all_moves( board, player, possible_moves, possible_scores);


	//now need to actually choose the move amongst the vector
	//see if the vector of tiles is from your hand or just a general vector

	if(possible_moves.size()==0)
	{//means no playable placement moves
		Move m("PASS", player);
		cout<<"CPUL IS PASSING"<<endl;
		return m;
	}
	int max_tiles = (possible_moves[0].tileVector ()).size(); int  max_tiles_ref = 0;

	for(int i = 1 ; i< (int)possible_moves.size(); i++)
	{
		int move_tiles_size = ( possible_moves[i].tileVector ()).size();//number of tiles for the move
		if(move_tiles_size  > max_tiles)
		{
			max_tiles = move_tiles_size;
			max_tiles_ref = i;
		}
	}
	cout<<"MAX NUMBER OF TILES USED FOR THE MOVE IS:"<< max_tiles<<endl;

	return possible_moves[max_tiles_ref];

	 

	
}