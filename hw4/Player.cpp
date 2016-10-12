#include "Player.h"
//blank = eg for make where k is a ? then ma?ke
//to lower to use a lower case letter or toupper for upper case letter - remember to make inputs
//remember start is a double word
	Player::Player (int handsize, Bag& bag)
	{score = 0;
		 max_handsize = handsize;
		//initialise tile set
			
			std::set<Tile*> drawn_tiles = bag.drawTiles(handsize);

			std::set<Tile*>::iterator it;
	 		for (it=drawn_tiles.begin(); it!=drawn_tiles.end(); ++it)
	 		{
	 			std::cout <<" [" << (*it)->getLetter() << ", "<< (*it)->getPoints() << "]";
				current_tiles.insert(*it) ;
	 		}

	}


	std::string Player::make_upper(std::string a)
	{
		std::string b = "";
		for(unsigned int i =0 ; i<a.size();i++)
		{
			b+=toupper(a[i]);
		}
		return b;
	}


	std::string Player::make_lower(std::string a)
	{
		std::string b = "";
		for(unsigned int i =0 ; i<a.size();i++)
		{
			b+=tolower(a[i]);
		}
		return b;
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

 	bool Player::tiles_present(std::string letters, std::vector <Tile*>& tiles_seen)
 	{
 		//std::vector <Tile*> tiles_seen;
 		unsigned int number_of_letters = letters.size();

		std::set<Tile*>::iterator it;
	 	for (unsigned int i=0; i<number_of_letters; ++i)
	 	 {  //looping through each of the letter
			//for each letter checking for a match

	 		for (it=current_tiles.begin(); it!=current_tiles.end(); ++it)
	 		{//iterating through each of the tiles in hand
	 			
	 			Tile* current_tile_ptr = *it;
	 			if((current_tile_ptr)->getLetter () == letters[i])
				{//if letter of a tile matches the inputted letter
					bool seen = false;

					for(unsigned int j = 0; j<tiles_seen.size(); j++)
					{//iterating through the letters seen vector and seeing if ptr matchs any of the seen vectors
						if(tiles_seen[j]==current_tile_ptr)
						{//if its  a pointer thats already been seen
							seen = true;
							break;
						}
									
					}
					if(!seen)
					{
						tiles_seen.push_back(current_tile_ptr);
						//std::cout<<"Tile"<<letters[i]<< "present"<<std::endl;
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

		std::vector <Tile*> tiles_seen;//simply meant to satsify prototype of tile_present, otherwise unused

	 	int number_of_tiles=tiles_2_B_Exchanged.size();
	
		if(tiles_present(tiles_2_B_Exchanged, tiles_seen))
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
						break;//if already removed once do not want to remove all instances of it
	 				}
	 			}
	 		}

	 		//now need to remove from bag and add back to the hand

	 		std::set<Tile*> set_from_bag = bag.drawTiles(number_of_tiles);
	 		std::cout<<"number of tiles being drawn are :"<< number_of_tiles<< std::endl;
	 		//this gives the set of tiles from the bag
	 		std::cout<<"Tile set from bag is : ";
	 		
	 		std::set<Tile*>::iterator it;

	 		for (it=set_from_bag.begin(); it!=set_from_bag.end(); ++it)
	 			{//iterating through each of the tiles in set from bag and adding to the hand
	 				std::cout<< (*it)->getLetter ();
	 			}
	 			std::cout<<std::endl;

	 		//now need to iterate through the set and add back to the hand
	 		//for insert you use a tile* so that would be *it
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


bool Player::valid_place(char dir, int s_row, int s_column, std::string tiles, Board& board_obj, Dictionary& dict, std::vector <Tile*>& tiles_seen, bool first_move)//here board is passed by value not reference
 {//do ajacent = true for sides which has not yet been done

 //check if first word since that must be placed on the start tile bool first move
 	//except first, newly formed word must be in contact with some letters already on board
 //checks if placement is legal
 		//remember these rows and columns start from 1 not 0
 	//tiles is the string of tiles to be placed at the postion s_row,  s_column in direction dir
//check if lower vs upper case causes issues
//check word size out of bounds


 	 	std::string** board = board_obj.get_board();
 	 	//std::vector <Tile*> tiles_seen;

 	if(tiles_present(tiles, tiles_seen)==false)
 	{
 		
 		std::cout<<"Tiles are not present in valid"<<std::endl;
 		return false;//if the inputted tiles are not present
 	}
 	if(board[s_row][s_column][0]!='.')
 	{
 		
 		std::cout<<"Placed spot is occupied"<<std::endl;
 		return false;//if position being placed at is occupied
//All the possible words formed
 	}


 	bool adjacent = false;//checks if newly placed word is adjacent to previous words
 				



 	int input_size = tiles.size();
 	int curr_row = s_row;
 	int curr_column = s_column;

 	if(dir == '-')
 	{
 		std::string curr_horizontal_word="";

 		if(first_move)
 		{
 			if(s_column > board_obj.get_start_column())return false;
 			
			if(s_column< board_obj.get_start_column() && (s_column+input_size-1)< board_obj.get_start_column() )return false;	
 			if(s_row != board_obj.get_start_row())
 			{
 			
 			return false;
 			}
 			adjacent = true;//if it is the first move cant be adjacent to anything
 		}


 		curr_column--;
 		//now one column to the left
 		if(curr_column>-1)
 		{//adding the letters to the left
 			while(board[curr_row][curr_column][0]!='.')//i.e. not unfilled tile
 			{
 				adjacent = true;//in contact with word to the left of it
 				std::string let_at_board_pos = "";
 				let_at_board_pos += tolower(board[curr_row][curr_column][0]);
 				curr_horizontal_word= let_at_board_pos +curr_horizontal_word;

 				curr_column--;
 				if(curr_column==-1)break;
 			}
 		}
 		
 		//resetting the column to start
 		curr_column = s_column;


 		//first checking each vertically formed word


 		for(int i = 0; i<input_size && curr_column< board_obj.get_width(); i++)
 		{//looping through postions of each of the input characters and checking each vertically formed word in that column as its added to the horizontal
 			
 			// std::cout<<"CHARACTER AT BOARD IS::"<<board[curr_row][curr_column][0]<<std::endl;
 			// std::cout<<"COLUMN IS::"<<curr_column+1<<std::endl;
 			// std::cout<<"ROW IS::"<<curr_row+1<<std::endl;
 				
 			if(board[curr_row][curr_column][0]!='.')
 			{//if a vertically formed word is already there then skip over checking that word
 			//add the letter to you current word
 			//add this code above
 				//std::cout<<"ENTERING THE ALREADY PRESENT LETTERS"<<board[curr_row][curr_column][0]<<std::endl;
 				adjacent = true;//in contact with a word which is in the middle of this one
 				curr_horizontal_word+= tolower(board[curr_row][curr_column][0]);
 				curr_column++;
 				i--;//since input letter is not being used dont want that to increment
 				continue;

 			}

 			curr_horizontal_word+=tiles[i];

 			std::string curr_vertical_word="";
 			curr_vertical_word+=tiles[i];//tile at that position
 			curr_row--;//going to the spot a row above
 			if(curr_row>-1)
 			{
 				while(board[curr_row][curr_column][0]!='.')
 				{//going upward
 			 	//if equal to dot then it is empty
 				//because the 0th position always contains the letter
 				
 				adjacent = true;//means there is a word upward
 				std::string let_at_board_pos = "";
 				let_at_board_pos += tolower(board[curr_row][curr_column][0]);

 				curr_vertical_word = let_at_board_pos +curr_vertical_word;
 				curr_row--;
 				if(curr_row<0)break;
 				}
 			}
 			

 			 curr_row = s_row;
 			 //curr_column = s_column;

 			  curr_row++;//going downward

 			if(curr_row<board_obj.get_height())
 			{
 				while(board[curr_row][curr_column][0]!='.')
 				{	//going down
 			 		//if equal to dot then it is empty
 					//because the 0th position always contains the letter


 					adjacent = true;//means there is a word downward
 					curr_vertical_word += tolower(board[curr_row][curr_column][0]);
 					curr_row++;
 					if(curr_row==board_obj.get_height())break;
 				}
 			}
 			
 			//finished going downward so reset the row
 			 curr_row = s_row;
 			if(!dict.is_present(curr_vertical_word)&& (curr_vertical_word.size()>1))
 				{
 					std::cout<<"vertically formed word"<<curr_vertical_word<<"is not in Dictionary"<<std::endl;
 					return false;
 				}
 			curr_column++;
 		}

 		//keep adding elements to the right until empty
 		//now checking the horizontally formed main word
 		//curr_column++;
 		if(curr_column<board_obj.get_width())
 		{
 			while(board[curr_row][curr_column][0]!='.' && curr_column< board_obj.get_height())
 			{//going rightward beyond word
 			 //if equal to dot then it is empty
 				//because the 0th position always contains the letter

 				adjacent = true;//means there is a word to the right of the present word
 				curr_horizontal_word += tolower(board[curr_row][curr_column][0]);
 				curr_column++;
 				if(curr_column==board_obj.get_width())break;
 			}	
 		}
 		

 		if(!dict.is_present(   make_lower(curr_horizontal_word)  )   )
 			{
 				
 				std::cout<<"Horizontal word is:"<<curr_horizontal_word<<std::endl;
 				std::cout<<"!dict.is_present(curr_horizontal_word)"<<std::endl;
 					return false;
 			}
 	}

 	else if(dir == '|')
 	{
 		//here vertical_word will be the main word formed by the letters while each horizontal will need to be checked

 		std::string curr_vertical_word="";

 		if(first_move)
 		{
 			if(s_row > board_obj.get_start_row())return false;//begins from below start and goes downward
			if(s_row< board_obj.get_start_row() && (s_row+input_size-1)< board_obj.get_start_row() )return false;//doesnt cross	
 			if(s_column != board_obj.get_start_column())return false;//different column from start
 			
 			adjacent = true;//if it is the first move cant be adjacent to anything
 		}
 	

 	 	curr_row--;//now one row above
 		if(curr_row>-1)
 		{//adding the letters to the top of the vertical word
 			while(board[curr_row][curr_column][0]!='.')//i.e. not unfilled tile
 			{
 				adjacent = true;//in contact with word to the top of it
 				std::string let_at_board_pos = "";
 				let_at_board_pos += tolower(board[curr_row][curr_column][0]);
 				curr_vertical_word= let_at_board_pos +curr_horizontal_word;

 				curr_row--;
 				if(curr_row==-1)break;
 			}
 		}
 		
 		//resetting the row to start
 		curr_row = s_row;


 		//first checking each horizontally formed word as you iterate down the vertical word


 	 	for(int i = 0; i<input_size && curr_row< board_obj.get_height(); i++)
 		{//looping through postions of each of the input characters and checking each vertically formed word in that column as its added to the horizontal
 			
 			// std::cout<<"CHARACTER AT BOARD IS::"<<board[curr_row][curr_column][0]<<std::endl;
 			// std::cout<<"COLUMN IS::"<<curr_column+1<<std::endl;
 			// std::cout<<"ROW IS::"<<curr_row+1<<std::endl;
 				
 			if(board[curr_row][curr_column][0]!='.')
 			{//if a vertically formed word is already there then skip over checking that word
 			//add the letter to you current word
 			//add this code above
 				//std::cout<<"ENTERING THE ALREADY PRESENT LETTERS"<<board[curr_row][curr_column][0]<<std::endl;
 				adjacent = true;//in contact with a word which is in the middle of this one
 				curr_vertical_word+= tolower(board[curr_row][curr_column][0]);
 				curr_row++;
 				i--;//since input letter is not being used dont want that to increment
 				continue;

 			}

 			curr_vertical_word+=tiles[i];

 			std::string curr_horizontal_word="";
 			curr_vertical_word+=tiles[i];//tile at that position
 			curr_column--;//going to the spot a column to the left
 			if(curr_column>-1)
 			{
 				while(board[curr_row][curr_column][0]!='.')
 				{//going leftward
 			 	//if equal to dot then it is empty
 				//because the 0th position always contains the letter
 				
 				adjacent = true;//means there is a word leftward
 				std::string let_at_board_pos = "";
 				let_at_board_pos += tolower(board[curr_row][curr_column][0]);

 				curr_horizontal_word = let_at_board_pos +curr_horizontal_word;
 				curr_column--;
 				if(curr_column<0)break;
 				}
 			}
 			
 			 curr_column = s_column;//resetting the column

 			  curr_column++;//going rightward

 			if(curr_row<board_obj.get_height())
 			{
 				while(board[curr_row][curr_column][0]!='.')
 				{	//going right
 			 		//if equal to dot then it is empty
 					//because the 0th position always contains the letter


 					adjacent = true;//means there is a word downward
 					curr_horizontal_word += tolower(board[curr_row][curr_column][0]);
 					curr_column++;
 					if(curr_column==board_obj.get_width())break;
 				}
 			}
 			
 			//finished going rightward so reset the column
 			 curr_column = s_column;
 			if(!dict.is_present(curr_horizontal_word)&& (curr_horizontal_word.size()>1))
 				{
 					std::cout<<"horizontally formed word"<<curr_horizontal_word<<"is not in Dictionary"<<std::endl;
 					return false;
 				}
 			curr_row++;
 		}

 	// 	//keep adding elements to the right until empty
 	// 	//now checking the horizontally formed main word
 	// 	//curr_column++;
 	// 	if(curr_column<board_obj.get_width())
 	// 	{
 	// 		while(board[curr_row][curr_column][0]!='.' && curr_column< board_obj.get_height())
 	// 		{//going rightward beyond word
 	// 		 //if equal to dot then it is empty
 	// 			//because the 0th position always contains the letter

 	// 			adjacent = true;//means there is a word to the right of the present word
 	// 			curr_horizontal_word += tolower(board[curr_row][curr_column][0]);
 	// 			curr_column++;
 	// 			if(curr_column==board_obj.get_width())break;
 	// 		}	
 	// 	}
 		

 	// 	if(!dict.is_present(   make_lower(curr_horizontal_word)  )   )
 	// 		{
 				
 	// 			std::cout<<"Horizontal word is:"<<curr_horizontal_word<<std::endl;
 	// 			std::cout<<"!dict.is_present(curr_horizontal_word)"<<std::endl;
 	// 				return false;
 	// 		}
 	// }

 	


































































 	if(!adjacent)
 	{
 		std::cout<<"Horizontal word is:"<<curr_horizontal_word<<std::endl;
 		std::cout<<"placed tile not adjacent"<<std::endl;
 		std::cout<<"value of adjacent is : "<< adjacent <<std::endl;
 		return false;
 	}

 	return true;
 }

 	void Player::place( char dir, int row, int column, std::string tiles, Board& board_obj, Dictionary& dict, Bag& bag, bool first_move)
	{	//ACTUAL GAMEPLAY AND SCORING NEED TO BE DONE

		//placed instructions given with spaces between
		//add in the scoring later after figuring out the placement
		//can do scoring by reference in valid place - need to add the score and the vertical direction valid and code
		//newly placed word should have some form of intersection with board present letters else invalid



		std::string** board = board_obj.get_board();
		std::vector <Tile*> hand_tiles_for_input_letters;
		//contains pointers to the tiles in hand used

		row--;column--;//changing rows and columns to start from 0 not 1
//(char dir, int s_row, int s_column, std::string tiles, Board& board_obj, Dictionary& dict)//here board is passed by value not reference
		
		if(! Player::valid_place( dir, row, column, tiles, board_obj, dict, hand_tiles_for_input_letters, first_move))
		{//if invalid place
		 //assuming no spaces between tiles but just a string of the tiles
			
			std::cout<<"Invalid place"<<std::endl;
			return;
		}

		else
		{//deemed valid and board = row, column
			int move_score = 0, w_2_cntr = 0, w_3_cntr = 0;
			//c_row, c_column are the current positions on the board of the program
			for(unsigned int i = 0; i< tiles.size() ;++i)
			{
				Tile* curr_tile =hand_tiles_for_input_letters[i];

				 if(board[row][column][0] == '.')
			   {//means unoccupied spot

			   	

			   	// if(board[row][column][1] == '2')//double letter
			   	// {
			   	// 	move_score+= (2*tile_score);
			   	// }


			   	//remember before replacing the values like this, get the score from the tile
			   	
			   		if(curr_tile->isBlank ())
			   		{
			   			std::cout<<"Enter use of tile"<<std::endl;
			   			char use;
			   			std::cin>>use;
			   			curr_tile->useAs(toupper(use));
			   		}

			   		std::stringstream ss;
			   		ss << curr_tile->getPoints();
			   		std::string tile_points;
			   		ss>>tile_points;
			   	//converting int to string score

			   		board[row][column]=  curr_tile->getUse() + tile_points + " ";


			   		//only if something is being placed then you want to erase the tile from hand if not then dont

			   		current_tiles.erase(curr_tile);

			   		std::set<Tile*> drawn_tiles = bag.drawTiles(1);

					std::set<Tile*>::iterator it;
	 				for (it=drawn_tiles.begin(); it!=drawn_tiles.end(); ++it)
	 				{
	 					std::cout<<"Drawn tiles are"<<std::endl;
	 					std::cout <<" [" << (*it)->getLetter() << ", "<< (*it)->getPoints() << "]";
						current_tiles.insert(*it) ;
	 				}

			   }

			   else {i--;}

				if(dir == '|')
				{
					row++;
				}
				else if(dir == '-')
				{
					column++;
				}
				//curr_tile = NULL;
				//erase takes in the position


				 
			   	
			}





			//score +=move_score;

		}
	 	

	 	board_obj.set_board(board);
 	}

