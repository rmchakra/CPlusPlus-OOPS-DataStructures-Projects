#include "lec.h"
Scrabble::~Scrabble() 
{
	delete moves;
	delete place_dir;
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < cols; j++) 
		{
		delete board[i][j];
		}
	delete board[i];
	}
	delete board;
	delete g;
	delete tiles;
	delete hand;
	delete play;
	delete h1;
	delete v1;
	delete window;
}
Scrabble::Scrabble(QApplication *app, int r, int c) 
{
	rows = r;
	cols = c;
	this->app = app;
	h1 = new QHBoxLayout;
	v1 = new QVBoxLayout;
	moves = new QComboBox;
	window = new QWidget;
	g = new QGridLayout;
	board = new QPushButton**[rows];
	for (int i = 0; i < rows; i++) 
	{
		board[i] = new QPushButton*[cols];
		for (int j = 0; j < cols; j++) 
		{
			board[i][j] = new QPushButton;
			g->addWidget(board[i][j],i+1,j+1);
			QObject::connect(board[i][j], SIGNAL(clicked()), this, SLOT(act()));
		}
	}//CREATES A BOARD AND CONNECTS EACH ONE TO THE ACT FUNCTION/SLOT

	window->setLayout(v1);
	v1->addLayout(g);
	moves->addItem("Place");
	moves->addItem("Exchange");
	moves->addItem("Pass");
	tiles = new QLineEdit();
	hand = new QLabel("[a,1][e,1][?,0][f,4][q,10][p,3][u,1]");
	play = new QPushButton("Act");
	v1->addLayout(h1);
	h1->addWidget(hand);
	h1->addWidget(moves);
	h1->addWidget(tiles);
	h1->addWidget(play);

	
	place_dir = new QComboBox;
	place_dir->addItem("|");
	place_dir->addItem("-");
	v1->addWidget(place_dir);
	window->setWindowTitle("Scrabble");
	window->show();
}
void Scrabble::act()
{
	QString str = tiles->text();
	QPushButton *called = (QPushButton*) QObject::sender();
	int i=0,j=0;
	for (int x = 0; x < rows; x++) 
	{
		for (int y = 0; y < cols; y++) 
		{
			if (board[x][y] == called) 
			{
				i = x;
				j = y;
			}
		}
	}
	for (QString::iterator it = str.begin(); it != str.end(); ++it) 
	{
		if (j < cols)
		{

			board[i][j]->setText(*it);
			(board[i][j])->setEnabled(false);
			//std::cout<< ((board[i][j])->text()).toStdString();
		}

		j++;
	}
}