#ifndef HEADERS_H
#define HEADERS_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include "Board.h"
#include "Dictionary.h"
#include "Player.h"
#include "Tile.h"
#include "Bag.h"
#include "Board.h"
#include "Board.h"
#include <QObject>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QApplication>
#include <QLabel>
#include <QComboBox>
#include <QString>
#include <QMessageBox>
#include <QMessageBox>




class Sqt : public QWidget 
{
	Q_OBJECT

	public slots:
	void q_place();	
	void n_place();//Anything Except Place

	public:
	Sqt(QApplication *app, Board& b, Dictionary& d, Bag& ba,unsigned int & hs);
	~Sqt();
	QWidget* return_window(){return window;}
	void pre_move_endgame();
	void post_move_endgame();//checks for endgame and performs the changes needed at the end of every move
	void endgame(QString);
	void invalid_move(QString reason);

	private:
	QApplication *app;
	QPushButton ***pb_board, *play;
	QLineEdit *tiles;
	QLabel *hand;//THESE ARE THE TILES CURRENTLY IN MY HAND
	QComboBox *moves;
	QWidget *window;
	QHBoxLayout *h1;
	QVBoxLayout *v1;
	QLabel *s_move;

	QVector <QLabel*> player_names;

	QHBoxLayout *for_s_name;
	QGridLayout *g;
	int rows;
	int cols;
	QComboBox *place_dir;
    std::string** board;
    QLabel *instructions;




    QGridLayout *curr_score_box;//every move displays the current scores of the players row 0 just is names of all
 	QVector <QLabel*> curr_score;//each curr_score[player_ref] needs to be set to new value after each place


    QLabel *curr_player_name;

    int player_ref;//which player is performing the actions
    bool allpassed;//have all the plahyers passed




	std::vector<Player> players;//each of the players
	int number_of_players;//number of players
    Board& mb;//this is my board
    Dictionary& dict;
    Bag& bag;
    unsigned int & hand_size;


    public slots:
    void setup(QVector<QString>, int );

};
#endif // HEADERS_H
