#ifndef PLAYER_H_
#define PLAYER_H_
#include <"Tile.h">
#include <"Bag.h">


class Player {
public:
	Player ()
	{score = 0;
		//initialise tile set
	}

	bool no_tiles()  { return (current_tiles.size()==0)); }

	std::string return_name() {return name;}
	void set_name(std::string name_input) {name = name_input;}

	std::string return_score() {return score;}
	void set_score(int score_) {score = score_;}

	void print_current_tiles()
	 {
	 	std::cout <<"Your current tiles:";
	 	for (std::set<Tile*>::iterator it=current_tiles.begin(); it!=current_tiles.end(); ++it)
	 	{
	 		std::cout <<" [" <<it->getLetter(); <<", "<<it->getPoints()<<"]"
	 	}
	 	std::cout <<endl;
 	}

 	void exchange_tiles(std::string tiles_2_B_Exchanged, Bag& bag)
	{//remember to do duplicate checking

	 	int number_of_tiles=tiles_2_B_Exchanged.size();
	 	
	 	for (int i=0; i<number_of_tiles; ++i)
	 	{
			Tile* it = current_tiles.find (tiles_2_B_Exchanged[i]);
			if(it==current_tiles.end())
				{cout<<"Tile not present"}
			else
			{
				current_tiles.erase(it);
				current_tiles.insert(bag.drawTiles(number_of_tiles));
			}
	 	}
	 	
 	}

private:
	string name;
	int score; 
	std::set<Tile*> current_tiles;
};





#endif /* PLAYER_H_ */