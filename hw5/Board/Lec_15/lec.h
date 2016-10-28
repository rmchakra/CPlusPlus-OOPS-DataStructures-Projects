#ifndef HEADERS_H
#define HEADERS_H
#include <QObject>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QApplication>
#include <QLabel>
#include <QComboBox>
#include <iostream>




class Scrabble : public QWidget 
{
	Q_OBJECT

	public slots:
	void act();

	public:
	Scrabble(QApplication *app, int r, int c);
	~Scrabble();

	private:
	QApplication *app;
	QPushButton ***board, *play;
	QLineEdit *tiles;
	QLabel *hand;
	QComboBox *moves;
	QWidget *window;
	QHBoxLayout *h1;
	QVBoxLayout *v1;
	QGridLayout *g;
	int rows;
	int cols;
	QComboBox *place_dir;
};
#endif // HEADERS_H

