#include "Scrabble_funcs.h"

bool valid_move(Game& game, string command) 
{

	Player* curr_player = game.getCurrentPlayer(); 
	try
	{

		cout<<"COMMAND IS :"<<command <<endl;
		Move m(command, *curr_player); 

		if (m.isPass()) 
		{		
			cout<<"PASSING"<<endl;
			game.makeMove(m);
			return true;
		}

		if (!game.bagEmpty())
		{
			game.refillTiles(); 
		}
		if (m.isWord()) 
		{ // PLACE command

			game.makeMove(m);

			cout <<"WORDS FORMED ARE: ";

			vector<string> recent_words= game.getRecentWords();

	 		for (vector<string>::iterator it=recent_words.begin(); it!=recent_words.end(); ++it)
	 		{
	 			//std::cout <<" [" << (*it)->getLetter() << ", "<< (*it)->getPoints() << "]";
				cout<<(*it) << " " ;
	 		}

	 		cout<< endl;
			cout << "MOVE Score = " << game.getRecentScore() << endl;
			cout << "New Score of :"<<curr_player->getName ()<<"IS :" << curr_player->getPoints() << endl;
		}
		if(m.isExchange ())
		{
			game.makeMove(m);
		}


	}
	catch(...)
	{
		std::cout << "INCORRECT COMMAND "<<std::endl;
		return false;
	}

	return true;//if it crosses the catch
}

void gg_no_re(Game& game)//GOOD_GAME_NO_REMATCH
{

	// keep mouthful_t Game::finalSubtraction() in mind
	// see if I need to call it, or at least for 
	cout << "Winners are: " << endl;

	vector<string> winners = game.getWinners();

	for (int i = 0; i < (int)winners.size(); ++i)
	{
		cout << winners[i] << endl;
	}

}

void play(Game& game, vector <AI_Base*> AIS)
{
	
	string player_identity = (game.getCurrentPlayer ())->getName ();//now we have name of player as string)

	bool ai_flag = false;
	bool CPUS_flag = false;
	bool CPUL_flag = false;

	if( player_identity.size()>3)//so it doesnt seg fault if I try to get the substring
	{
		string type = strtoupper(player_identity.substr(0, 4));

		if(type == "CPUS")//position 0 for length of 4 gives first 4 characters if the string
		{//this is the max score AI which will take in the current player and perform the move for it
			ai_flag = true;
			cout<<"max score AI's turn"<< endl;
			CPUS_flag = true;
		}
		else if(type == "CPUL")//position 0 for length of 4 gives first 4 characters if the string
		{//this is the max letter AI which will take in the current player and perform the move for it
			ai_flag = true;
			CPUL_flag = true;
			cout<<"max letter AI's turn"<< endl;
		}

	}

	if(!ai_flag)
	{
		string command = scores_instruction_command(game);

		while (!valid_move(game, command))
		{
			command = scores_instruction_command(game);
		}
	}
	else
	{//AIs must make the move

		Board* board_ = game.getBoard ();
		Player* curr_player = game.getCurrentPlayer ();
		std::map<char, int> initialTileCount = game.initialTileCount();
		Move m;
		if(CPUS_flag)
		{
			m = (AIS[0])->getMove (*board_, *curr_player, initialTileCount);
		//valid_move(Game& game, string command); 
		}

		else if(CPUL_flag)
		{//here AI needs to make the move;

			m = (AIS[1])->getMove (*board_, *curr_player, initialTileCount);
			//valid_move(Game& game, string command); 
		}
		game.makeMove(m);

		 display_move(game, m);
	}

	

	

	if (game.getCurrentPlayer()->numberofTiles() == 0)
	{ //endgame case since it hasnt been refilled so bag must be empty and player has no tiles
		cout << game.getCurrentPlayer()->getName() << " USED ALL HAND TILES" << endl;
		vector<pair<std::string,int> > pair_giver_points_received = game.finalSubtraction();

		cout<<"Player GAVE Points :"<<endl;
		
		for (vector<pair<string,int> > ::iterator it=pair_giver_points_received.begin(); it!=pair_giver_points_received.end(); ++it)
     	{
      	 	cout<<it->first << ":" ;
	   		cout<<it->second << endl ;
     	}

	}


	game.finalizeMove ();
}



void display_move(Game& game, Move& m)
{
	string curr_player = game.getCurrentPlayer ()->getName ();
	cout<< "Player "<< curr_player << "chose to :";
	if(m.isPass ()){cout<<"PASS";}
	else
	{
		if(m.isExchange ())
		{
			cout<<"EXCHANGE THE TILES :";
		}
		if(m.isWord ())
		{
			cout<<"Place ";
			if(m.isHorizontal ()){cout<<"Horizontally";}
			else{cout<<"Vertically";}
			cout<<"at row "<< m.y()<< " and column "<< m.x()<< " ";

			cout<<"THE TILES :";
		}

			std::vector<Tile*> tile_vector = m.tileVector ();
			for(int i = 0; i < (int)tile_vector.size(); i++)
			{
				cout<< tile_vector[i]->getLetter ()<< tile_vector[i]->getPoints ()<< " ";
			}

	}

	cout << endl;
 	
}












string scores_instruction_command(Game& game)
{
	

	cout << (game.getCurrentPlayer())->getName() << ", it's your move."<<endl;
	cout<<"Current Scores are ::::"<<endl;


	vector<pair<string,int> > pair_name_score= game.getScores();

	for (vector<pair<string,int> > ::iterator it=pair_name_score.begin(); it!=pair_name_score.end(); ++it)
     {
       cout<<it->first << ":" ;
	   cout<<it->second << endl ;
     }



    cout<< game.getBoard()->getDisplay();






	cout<<"To pass your turn, type PASS"<<endl;
	cout<<"To discard tiles, type EXCHANGE, followed by a string of those tiles."<<endl;
	cout<<"To place a word, type PLACE, followed by the following:"<<endl;
	cout<<"       first, either a | or - for vertical/horizontal placement;"<<endl;
	cout<<"       second, the row (from the top), the column (from the left),"<<endl;
	cout<<"       third, a sequence of letters to place;"<<endl;
	cout<<"       to use a blank tile, type ? While the letter is being placed you will be prompted for the letter you wish to place"<<endl;

	cout<<"current tiles of"<<(game.getCurrentPlayer())->getName()<<"are:"<<endl;
	cout<<(game.getCurrentPlayer())->getHand()<< endl;
	cout<<endl;
	std::cout<<"ENTER COMMAND:"<<std::endl;


	string command;

	getline(std::cin, command);//getting the command
	command = strtoupper(command);

	return command;
}
