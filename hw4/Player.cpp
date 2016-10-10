#include <"Player.h">
//how do I make a copy of my board since it is pointer so modifying will edit orig board even if invalid
using namespace std;

	Player::Player ()
	{score = 0;
		//initialise tile set
	}

	bool Player::no_tiles()  { return (current_tiles.size()==0)); }

	std::string return_name() {return name;}
	void Player::set_name(std::string name_input) {name = name_input;}

	std::string Player::return_score() {return score;}
	void Player::set_score(int score_) {score = score_;}

	void Player::print_current_tiles()
	 {
	 	std::cout <<"Your current tiles:";
	 	for (std::set<Tile*>::iterator it=current_tiles.begin(); it!=current_tiles.end(); ++it)
	 	{
	 		std::cout <<" [" <<it->getLetter(); <<", "<<it->getPoints()<<"]";
	 	}
	 	std::cout <<endl;
 	}

 	bool Player::tiles_present(std::string tiles)
 	{
 		int number_of_tiles=tiles_2_B_Exchanged.size();
	
	 	for (int i=0; i<number_of_tiles; ++i)
	 	{ //check legality of exchange first	
			Tile* it = current_tiles.find (tiles_2_B_Exchanged[i]);
			if(it==current_tiles.end())
			{
				cout<<"Tile"<< tiles_2_B_Exchanged[i]<< "not present";
				return false;
			}
	 	}

	 	return true;
 	}

 	void Player::exchange_tiles(std::string tiles_2_B_Exchanged, Bag& bag)
	{//remember to do duplicate checking

	 	int number_of_tiles=tiles_2_B_Exchanged.size();
	
		if(tiles_present(tiles_2_B_Exchanged))
		{
			for (int i=0; i<number_of_tiles; ++i)
	 		{//perform actual exchange
			
			Tile* it = current_tiles.find (tiles_2_B_Exchanged[i]);
			current_tiles.erase(it);
			current_tiles.insert(bag.drawTiles(number_of_tiles));
	 		}
		}
 	}

 	void Player::place( char dir, int row, int column, std::string tiles, Board& board_obj)
	{//placed instructions given with spaces between

		row--;column--;//chaning rows and columns to start from 0 not 1
		
		if(! Player::valid_place( dir, row, column, tiles, board))
		{//if invalid place
		 //assuming no spaces between tiles but just a string of the tiles
			
			cout<<"Invalid place"<<endl;
			return;
		}

		else
		{//deemed valid and board = row, column
			int move_score = 0, 2w_cntr = 0, 3w_cntr = 0, occ_tiles=0;

			for(int i = 0; i< (tiles.size() + occ_tiles);i++)
			{
				
				 if(board[row][column][0] == '.')
			   {//means unoccupied spot

			   	Tile* T = current_tiles.find (tiles[i]);
			   	stringstream ss;
			   	T->score >> ss;
			   	string tile_score;
			   	ss>>tile_score;
			   	//converting int to string score

			   	if(board[row][column][1] == '2')//double letter
			   	{
			   		move_score+= (2*tile_score);
			   	}



			  

			   }

			   else
			   {
			   	occ_tiles++;
			   }

				if(dir == '|')
				{
					row++;
				}
				else if(dir == '-')
				{
					column++;
				}

				 T = NULL;
			   	current_tiles.erase(current_tiles.find (tiles[i]);
			   	current_tiles.insert(bag.drawTiles(number_of_tiles));
			}





			score +=move_score;

		}
	 	
 	}

 	bool Player::valid_place( char dir, int row, int column, std::string tiles, Board board_obj, Dictionary& d)//here board is passed by value not reference
 	{//checks if placement is legal
 		//remember these rows and columns start from 1 not 0

 		if(tiles_present(tiles)==false)return false;


 		vector <string> words_formed;

 		for(int i = 0; i< words_formed.size();i++)
 		{
 			if(! d.is_present(words_formed[i])) return false;
 		}

 		return true;
 	}