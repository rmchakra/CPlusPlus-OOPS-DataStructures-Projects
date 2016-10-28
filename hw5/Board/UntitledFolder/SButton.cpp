#include "SButton.h"


  void SButton::placed_letter_pts(/*std::string l*/)
  {
  	std::string l = "N3 ";
  	setText(QString::fromStdString(l));
  	setEnabled(false);
  }

SButton::SButton(int row_number, int column_number, std::string c, QWidget *parent) : QPushButton (parent)
 {
 	row=row_number; col =column_number; setText(QString::fromStdString(c));
    connect (this, SIGNAL(clicked()), this, SLOT(emits_pos()));
    //Later connect the clicked to a function that will emmit
    connect (this, SIGNAL(pos(int,int)), this, SLOT(placed_letter_pts(/*std::string l = "N3 "*/)));
    
    show();
   
 }

 void SButton::emits_pos()
 {
 	emit pos(row, col);
 }

