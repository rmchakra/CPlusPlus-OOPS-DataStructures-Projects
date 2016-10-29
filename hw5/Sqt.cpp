#include "Sqt.h"
Sqt::~Sqt() 
{
	delete instructions;
	delete moves;
	delete place_dir;
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < cols; j++) 
		{
			delete pb_board[i][j];
		}
	delete pb_board[i];
	}
	delete pb_board;
	delete g;
	delete tiles;
	delete hand;
	delete play;
	delete h1;
	delete v1;
	delete window;
	delete curr_score_box;

	//curr_score->clear();
	//delete curr_score;
	//delete player_names;
	delete for_s_name;
	delete s_move;

}

void Sqt::pre_move_endgame()
{//checked at start of every move remember the player ref incrementation needs to done at the end of move
	
	//create a pop up msg box that tells you the game has ended like in the lab and closes this window
	if( (bag.tilesRemaining()==0 ) && ((players[player_ref]).return_current_handsize() == 0))
		{
				endgame("ENDGAME: No tiles in bag and no tiles in hand");
		}
}

void Sqt::post_move_endgame()
{

	int players_score = (players[player_ref]).return_score();
	std::stringstream ss;
	ss<<players_score; 
	std::string ps;
	ss>>ps;
	QString nps = QString::fromStdString(ps);
	(curr_score[player_ref])->setText(nps);

	//score should be changed before the player referenced is changed

	if(player_ref == ((int)players.size()-1)) 
	{//reached the last player then goes to -1 state which is incremented at the end of the loop
		if(allpassed == true)
		{
			endgame("ENDGAME: All PASSED"); 

	std::cout<<"REACHES if that calls ENDGAME";

			return;}
		
		player_ref=-1;
		allpassed = true;
			//resetting allpassed back to true
	}
	player_ref++;

//


	//player names is a qlabel 
	curr_player_name->setText((player_names[player_ref])->text());
	hand->setText(QString::fromStdString((players[player_ref]).return_str_current_tiles()));

}

void Sqt::setup(QVector<QString> player_nam, int np)
{//since this is first set it to the first players things
	number_of_players =np;

	int zero = 0, one = 1;

	//player_names = new QLabel*[np];

	for(int i = 0; i<number_of_players; i++)
	{
		Player p(hand_size, bag);
		p.set_name((player_nam[i]).toStdString());
		players.push_back(p);
		player_names.push_back(new QLabel(QString::fromStdString(players[i].return_name())));
		curr_score.push_back( new QLabel("0"));
		curr_score_box->addWidget(player_names[i],zero,i);	
		curr_score_box->addWidget(curr_score[i] , one , i);
	}

	curr_player_name->setText(player_names[0]->text());
	hand->setText(QString::fromStdString((players[0]).return_str_current_tiles()));


	//this->resize(/*this->width() or height in this order*/ 10, 10);

	window->show();
}
Sqt::Sqt(QApplication *app, Board& b, Dictionary& d, Bag& ba, unsigned int & hs) : mb(b), dict(d), bag(ba), hand_size(hs) 
{
		
	player_ref =0;
    allpassed = true;

	//BELOW THIS POINT IS QTBOARD creation

	board = b.get_board();
	rows = mb.get_height();
	cols = mb.get_width();
	this->app = app;
	h1 = new QHBoxLayout;
	v1 = new QVBoxLayout;
	moves = new QComboBox;
	window = new QWidget;
	g = new QGridLayout;
	pb_board = new QPushButton**[rows];
	for (int i = 0; i < rows; i++) 
	{
		pb_board[i] = new QPushButton*[cols];
		for (int j = 0; j < cols; j++) 
		{
			pb_board[i][j] = new QPushButton(QString::fromStdString(board[i][j]));
			g->addWidget(pb_board[i][j],i,j);
			QObject::connect(pb_board[i][j], SIGNAL(clicked()), this, SLOT(q_place()));
		}
	}//CREATES A pb_board AND CONNECTS EACH ONE TO THE ACT FUNCTION/SLOT

	std::string ins ="GAMEPLAY INSTRUCTIONS : ";
	ins += "To pass your turn, choose PASS from dropbox and click\n";
	ins +="To discard tiles enter string of tiles, choose EXCHANGE from dropbox and click.\n";
	ins +="To place a word, enter letters , followed by the following:\n";
	ins +="       first,choose vertical OR horizontal placement from drop down menu;\n";
	ins +="       second, click board at position to place\n";
	ins +="       to use a blank tile, type ? While the letter is being placed you will be prompted for the letter you wish to place\n";
	ins +="LEGEND:";
	ins +="... = empty tile || ";
	ins +=".d*= start spot|| ";
	ins +=".2 = double letter|| ";
	ins +=".3 = triple letter|| ";
	ins +=".d = double word|| ";
	ins +=".t = triple word ";



	instructions = new QLabel(QString::fromStdString(ins));
	v1->addWidget(instructions);

	window->setLayout(v1);
	v1->addLayout(g);//G IS THE GRID OF THE BOARD
	//moves->addItem("Place");

	for_s_name = new QHBoxLayout;
	v1->addLayout(for_s_name);
	curr_player_name = new QLabel("");
	for_s_name->addWidget(curr_player_name);
	s_move = new QLabel("'s turn");
	for_s_name->addWidget(s_move);

	//return_str_current_tiles()
	v1->addWidget(new QLabel("CURRENT SCORES"));
	curr_score_box = new QGridLayout;
	v1->addLayout(curr_score_box);

	moves->addItem("EXCHANGE");
	moves->addItem("PASS");
	tiles = new QLineEdit();
	hand = new QLabel("");
	play = new QPushButton("EXCHANGE/PASS");


	QObject::connect(play, SIGNAL(clicked()), this, SLOT(n_place()));



	v1->addLayout(h1);
	h1->addWidget(hand);
	h1->addWidget(moves);
	h1->addWidget(tiles);
	h1->addWidget(play);//Button for exchange or pass

	
	place_dir = new QComboBox;
	place_dir->addItem("VERTICAL");
	place_dir->addItem("HORIZONTAL");
	v1->addWidget(place_dir);
	window->setWindowTitle("SCRABBLE");


	//this->resize(/*this->width() or height in this order*/ 10, 10);

	QWidget::setMaximumSize(20, 20);
	//this->setMaximumHeight(15);
	//this->setMaximumWidth(15);
	
	//window->show();
}
void Sqt::q_place()
{//THIS IS THE PLACE FUNCTION FROM QT SIDE

	pre_move_endgame();
	allpassed = false;

	QString str = tiles->text();
	QString dir = place_dir-> currentText() ;

	QPushButton *called = (QPushButton*) QObject::sender();
	int i=0,j=0;
	for (int x = 0; x < rows; x++) 
	{
		for (int y = 0; y < cols; y++) 
		{
			if (pb_board[x][y] == called) 
			{
				i = x;
				j = y;//i =row, j = col of the pressed button
			}
		}
	}
	for (QString::iterator it = str.begin(); it != str.end(); ++it) 
	{
		
		if(dir == "HORIZONTAL")
		{
			if (j < cols)
			{

			pb_board[i][j]->setText(*it);
			(pb_board[i][j])->setEnabled(false);
			//std::cout<< ((pb_board[i][j])->text()).toStdString();
			}

			j++;
		}
		else
		{
			if (i < rows)
			{

			pb_board[i][j]->setText(*it);
			(pb_board[i][j])->setEnabled(false);
			//std::cout<< ((pb_board[i][j])->text()).toStdString();
			}

			i++;
		}

		
	}


	post_move_endgame();
}

void Sqt::n_place()
{//Anything Except Place

	pre_move_endgame();	

	QString tiles_2_B_Exchanged_qs = tiles->text();
	std::string tiles_2_B_Exchanged = tiles_2_B_Exchanged_qs.toStdString();
	QString command = moves->currentText();
	//if youre just passing

	if( command == "EXCHANGE")
	{
		
		std::string exg_res = ((players[player_ref]).exchange_tiles(tiles_2_B_Exchanged, bag));
		if( exg_res!= "S")
		{//means it was invalid
			invalid_move(QString::fromStdString(exg_res));
			player_ref--;
		}
		else
		{allpassed = false;}


	}




	post_move_endgame();

}

void Sqt::endgame(QString reason)
{//Perform changes and score calculations
	QMessageBox msgBox;
	std::cout<<"REACHES ENDGAME";
	// Set message box text values
	msgBox.setWindowTitle("Game has Ended");
	msgBox.setText(reason);
	msgBox.exec();
}

void Sqt::invalid_move(QString reason)
{//Perform changes and score calculations
	QMessageBox msgBox;
	// Set message box text values
	msgBox.setWindowTitle("INVALID MOVE");
	msgBox.setText(reason);
	msgBox.exec();
}