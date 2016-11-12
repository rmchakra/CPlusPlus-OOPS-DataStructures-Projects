#include "CPUS.h"

Move CPUS::getMove (const Board & board, const Player & player, std::map<char, int> initialTileCount)
{
	vector<Move> possible_moves; vector<int> possible_scores;
	all_moves( board, player, possible_moves, possible_scores);

	if(possible_moves.size()==0)
	{//means no playable placement moves
		Move m("PASS", player);
		cout<<"CPUS IS PASSING"<<endl;
		return m;
	}

	int h_score = possible_scores[0], h_score_move_ref = 0;

	for(int i = 1; i< (int) possible_scores.size(); i++)
	{
		if(possible_scores[i]>h_score)
		{
			h_score = possible_scores[i], h_score_move_ref = i;
		}
	}

	return possible_moves[h_score_move_ref];

	//now need to actually choose the move amongst the vector
	
}