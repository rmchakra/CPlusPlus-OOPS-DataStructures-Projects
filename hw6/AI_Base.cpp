#include "AI_Base.h"


void AI_Base::all_moves( const Board & board, const Player & player, vector<Move>& possible_moves, vector<int>& possible_scores)
{
	int rows = board.getRows();
	int cols = board.getColumns();

	std::set<Tile*> hand_tiles = player.getHandTiles();

	string all_tiles = "";

	for (std::set<Tile*> ::iterator it=hand_tiles.begin(); it!=hand_tiles.end(); ++it)
	 {
	 	all_tiles+= ((*it)->getLetter ());
	 	//account for ? here. Can deal with that by passing in an array of all tiles
	 	//with all the possible chars
	 	//and change the function to take in an array and for loop for each position
	 	//if not ? then only runs once
	 } 


	//string all_tiles_with_points = player.getHand (); 
	//this needs to be just letters

	for(int i = 1; i<= cols; i++)
	{//since coordinates start with 1
		for (int j = 1; j <= rows; ++j)
		{
			
			//for each square theres a call for horizontal and then for vertical

			//get the string of tiles by string all_tiles = player.getHand ();
			//for the first call the tiles_being_placed will be empty

			moves_per_square(board, player, all_tiles, "", i, j, true, possible_moves,  possible_scores);//placing horizontally
			moves_per_square(board, player, all_tiles, "", i, j, false, possible_moves,  possible_scores);//placing vertically
			
		}
	}

}

//this currently generates all the permutations of varying sizes for an input string and can stop the perms
  void AI_Base::moves_per_square(const Board & board, const Player & player, string all_tiles, string tiles_being_placed,const int& x,const int& y, bool horizontal_bool, vector<Move>& possible_moves, vector<int>& possible_scores) 
{//make this take in a vector of moves and see if it gives all the legal words at a particular square
  //change this tiles being placed prefix check to the get words of the place after the move is created

	//cout << tiles_being_placed <<endl;

	vector <string> words; int move_score; bool valid = false;

	if(tiles_being_placed.size() == 0)//if it is occupied
	{//if the square isn't useable dont want it to recurse
		string first_tile = ""; first_tile+= all_tiles[0];

		Move m(x, y, horizontal_bool, first_tile, player);

		try
		{
			words = board.getWords (m, move_score, valid);
		}
		catch (MoveException &me) 
		{ return; }
		catch(...){return;}


	}


      else
     { 
     	
		Move m(x, y, horizontal_bool, tiles_being_placed, player);
		
		
		try
		{
			words = board.getWords (m, move_score, valid);//if it is out of bounds then we want it to stop the recursion
		}
		catch (MoveException &me) 
		{ return; }		

		for(int i = 0; i<(int)(words.size() -1); i ++)
		{//non-main direction words are part of the dictionary
			if(words[i].size()>1)//since dont want it to stop for single tiles just in the air
			{
				if(dict_words.find(words[i]) == dict_words.end())
				{//for that iteration 
					return;
				}
			}	
		}
		if(valid)
		{
			if(dict_words.find(words[words.size()-1]) != dict_words.end())//so word is part of dictionary
			{
				if(all_tiles.size()==0)//if all tiles from the hand have been used
				{
					move_score+=50;
				}
				possible_moves.push_back(m); possible_scores.push_back(move_score);
			}		
		}
			
	
		//this is for prefixes and to check that the last word is a prefix 
			if(prefixes.find(words[words.size() - 1]) == prefixes.end()) return; 
			//will not recurse further down that prefix check for prefix, 
			//but before that check if it is a word also for letters in the middle of the word 
			//on the bpard and letters after he placed tile remember to add it to the word search
     	}

  for( int i = 0; i < (int)all_tiles.length(); i++ )
     {
     	
     		moves_per_square(board, player, string(all_tiles).erase(i,1), tiles_being_placed + all_tiles[i], x, y, horizontal_bool, possible_moves, possible_scores);
     	
     }
}