#include "Player.h"
//how do I make a copy of my board since it is pointer so modifying will edit orig board even if invalid
//blank = eg for make where k is a ? then ma?ke
//to lower to use a lower case letter or toupper for upper case letter
	Player::Player (int handsize, Bag& bag)
	{score = 0;
		//initialise tile set
			
			std::set<Tile*> drawn_tiles = bag.drawTiles(handsize);

			std::set<Tile*>::iterator it;
	 		for (it=drawn_tiles.begin(); it!=drawn_tiles.end(); ++it)
	 		{
	 			std::cout <<" [" << (*it)->getLetter() << ", "<< (*it)->getPoints() << "]";
				current_tiles.insert(*it) ;
	 		}

	}

	bool Player::no_tiles()  { return (current_tiles.size()==0); }

	std::string Player::return_name() {return name;}
	void Player::set_name(std::string name_input) {name = name_input;}

	int Player::return_score() {return score;}
	void Player::set_score(int score_) {score = score_;}

	void Player::print_current_tiles()
	 {
	 	std::cout <<"Your current tiles:";
	 	std::set<Tile*>::iterator it;
	 	for (it=current_tiles.begin(); it!=current_tiles.end(); ++it)
	 	{
	 		std::cout <<" [" << (*it)->getLetter() << ", "<< (*it)->getPoints() << "]";
	 	}
	 	std::cout <<std::endl;
 	}

 	bool Player::tiles_present(std::string letters)
 	{//this will not check for duplcates. If theres a duplicate in the input then 
 		//keep a vector of bools so if already saw it then 1 else 0
 		std::vector <Tile*> tiles_seen;
 		unsigned int number_of_letters = letters.size();

		std::set<Tile*>::iterator it;
	 	for (unsigned int i=0; i<number_of_letters; ++i)
	 	 {  //looping through each of the letter
			//for each letter checking for a match

	 		for (it=current_tiles.begin(); it!=current_tiles.end(); ++it)
	 		{//iterating through each of the tiles in hand
	 			
	 			Tile* current_tile_ptr = *it;
	 			if((current_tile_ptr)->getLetter () == letters[i])
				{
					bool seen = false;

					for(unsigned int j = 0; j<tiles_seen.size(); j++)
					{//iterating through the letters seen vector and seeing if ptr matchs any of the seen vectors
						if(tiles_seen[j]==current_tile_ptr)
						{//if its not a pointer thats already been seen
							seen = true;
							break;
						}
									
					}
					if(!seen)
					{
						tiles_seen.push_back(current_tile_ptr);
						std::cout<<"Tile"<<letters<< "present";
						break;
					}

				}
	 			// std::cout <<" [" << (*it)->getLetter() << ", "<< (*it)->getPoints() << "]";
	 		}	 		
	 		// std::cout <<std::endl;
	 	}

	 	//if the size of freshly tiles_seen = number_of_letters then all the letters were matched
	 	//so exchange is legal
	 	return (tiles_seen.size() == number_of_letters);
 	}

 	void Player::exchange_tiles(std::string tiles_2_B_Exchanged, Bag& bag)
	{//remember to do duplicate checking


	 	int number_of_tiles=tiles_2_B_Exchanged.size();
	
		if(tiles_present(tiles_2_B_Exchanged))
		{
			for (int i=0; i<number_of_tiles; ++i)
	 		{//performing the removals from the tiles in hand and adding to bag
			
			
			//tiles_2_B_Exchanged[i] is a char while current_tiles is a tile*
	 			std::set<Tile*>::iterator it; 
				for (it=current_tiles.begin(); it!=current_tiles.end(); ++it)
	 			{//iterating through each of the tiles in hand
	 				if((*it)->getLetter() == tiles_2_B_Exchanged[i])
	 				{

						current_tiles.erase(it);
						bag.addTile(*it);
	 				}
	 			}
	 		}

	 		//now need to remove from bag and add back to the hand

	 		std::set<Tile*> set_from_bag = bag.drawTiles(number_of_tiles);
	 		//this gives the set of tiles from the bag

	 		//now need to iterate through the set and add back to the hand
	 		//for insert you use a tile* so that would be *it
	 		std::set<Tile*>::iterator it;
	 		for (it=set_from_bag.begin(); it!=set_from_bag.end(); ++it)
	 			{//iterating through each of the tiles in set from bag and adding to the hand
	 				current_tiles.insert(*it);
	 			}


	 		// std::set<Tile*>::iterator it;
	 		// for (int i=0; i<number_of_tiles; ++i)
	 		// {//removing from bag and adding to current hand
	 		// 	it=current_tiles.begin(); it!=current_tiles.end(); ++it
	 		// 	std::cout <<" [" << (*it)->getLetter() << ", "<< (*it)->getPoints() << "]";
	 		// }

	 		// current_tiles.insert(bag.drawTiles(number_of_tiles));
			//bag.draw tiles gives a set of tile*
		}

		else
		{
			std::cout<<"Tiles to be exchanged are not present"<<std::endl;
		}
 	}

 // 	void Player::place( char dir, int s_row, int s_column, std::string tiles, Board& board)
	// {//placed instructions given with spaces between

	// 	row--;column--;//chaning rows and columns to start from 0 not 1
		
	// 	if(! Player::valid_place( dir, row, column, tiles, board))
	// 	{//if invalid place
	// 	 //assuming no spaces between tiles but just a string of the tiles
			
	// 		cout<<"Invalid place"<<std::endl;
	// 		return;
	// 	}

	// 	else
	// 	{//deemed valid and board = row, column
	// 		int move_score = 0, w_2_cntr = 0, w_3_cntr = 0, occ_tiles=0, c_row = s_row, c_column = s_column;
	// 		//c_row, c_column are the current positions on the board of the program
	// 		for(int i = 0; i< (tiles.size() + occ_tiles);i++)
	// 		{
				
	// 			 if(board[row][column][0] == '.')
	// 		   {//means unoccupied spot

	// 		   	Tile* T = current_tiles.find (tiles[i]);
	// 		   	std::stringstream ss;
	// 		   	T->score >> ss;
	// 		   	string tile_score;
	// 		   	ss>>tile_score;
	// 		   	//converting int to string score

	// 		   	if(board[row][column][1] == '2')//double letter
	// 		   	{
	// 		   		move_score+= (2*tile_score);
	// 		   	}



			  

	// 		   }

	// 		   else
	// 		   {
	// 		   	occ_tiles++;
	// 		   }

	// 			if(dir == '|')
	// 			{
	// 				row++;
	// 			}
	// 			else if(dir == '-')
	// 			{
	// 				column++;
	// 			}

	// 			 T = NULL;
	// 		   	current_tiles.erase(current_tiles.find (tiles[i]);
	// 		   	current_tiles.insert(bag.drawTiles(number_of_tiles));
	// 		}





	// 		score +=move_score;

	// 	}
	 	
 // 	}

 	bool Player::valid_place( char dir, int s_row, int s_column, std::string tiles, Board board_obj, Dictionary& d)//here board is passed by value not reference
 	{//checks if placement is legal
 		//remember these rows and columns start from 1 not 0

 		if(tiles_present(tiles)==false)return false;


 		std::vector <std::string> words_formed;

 		for(unsigned int i = 0; i< words_formed.size();i++)
 		{
 			if(! d.is_present(words_formed[i])) return false;
 		}

 		return true;
 	}