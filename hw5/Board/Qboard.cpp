#include "Qboard.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QSpinBox>
#include <QLabel>
#include <QString>
#include <iostream>
#include <sstream>


//FOR W1 JUST USE A DATA CLASS AND GIVE IT ALL THE VALUES AND KEEP REFERRING TO THAT

Qboard::Qboard (Board& board, QWidget *parent) : QWidget (parent)
{
  mb = board;
  mainLayout = new QVBoxLayout;

  

}





















void Qboard::set_window_number(int a)
{

  window_number=a;

  QFormLayout *fl = new QFormLayout;
  
  if(window_number==0)
  {
    mainLayout->addWidget (new QLabel ("Please enter Number of Players"));

    //name = new QLineEdit;
    number = new QSpinBox;
    number->setMinimum (1); number->setMaximum(8); 
    number->setValue(1); number->setSingleStep(1);

    //fl->addRow ("&Name", name);
    fl->addRow ("Num&ber", number);

  }
  else if (window_number==1)
  {
     mainLayout->addWidget (new QLabel ("Please enter Names of Players"));

  }
  else if (window_number==2)
  {
    /* code */
  }

  //std::cout<<"WINDOW NUMBER IS:"<<window_number<<std::endl;
  
  
  mainLayout->addLayout (fl);

  QHBoxLayout *buttonLayout = new QHBoxLayout;
  quitButton = new QPushButton ("&Quit");
  confirmButton = new QPushButton ("&Confirm");
  buttonLayout->addWidget (confirmButton);
  buttonLayout->addWidget (quitButton);

  connect (confirmButton, SIGNAL(clicked()), this, SLOT(confirmPressed()));
  connect (quitButton, SIGNAL(clicked()), this, SLOT(quitPressed()));
  //connect (name, SIGNAL(returnPressed()), this, SLOT(confirmPressed()));

  mainLayout->addLayout (buttonLayout);


  //nameLabel = new QLabel("");
  numberLabel = new QLabel("");

  //QHBoxLayout *resultLayout = new QHBoxLayout;
 // mainLayout->addWidget(nameLabel);
  mainLayout->addWidget (numberLabel);


  setLayout (mainLayout);
}

void Qboard::closeEvent (QCloseEvent *event)
{
  std::cout << "Bye Bye.\n";
  //  event->accept();
  QWidget::closeEvent (event);
}

void Qboard::confirmPressed ()
{//JUST CREATE THE NEW WINDOW HERE
  //std::string userName = name->text().toStdString();
  if(window_number == 0)
  {
    number_of_players = number->value();
    emit W0(/*name->text(), */number_of_players);
  }

  else if(window_number == 1)
  {

    names =  new QString [number_of_players];
    //QString names[number_of_players];
    for(int i = 0; i<number_of_players;i++)
    {
      names[i]=name_inputs[i]->text();
      std::cout<<"EMMITING NAME: "<<names[i].toStdString()<<std::endl;
    }

    //emit W2send(names, number_of_players);
  }
 
  close();

  
}


void Qboard::W0confirmPressed (/*QString name = "no input",*/ int players)
{//this is effect on w1 of w0 being pressed
    number_of_players = players;
  QString play = QString::number(players);

  ///nameLabel->setText(name);
  //numberLabel->setText(play);

  name_inputs = new QLineEdit* [players];

  QFormLayout *fl = new QFormLayout;

  for(int i =0; i<players;i++)
  {
    //"player", i,"'s name is:",
    name_inputs[i] = new QLineEdit;
    fl->addRow("Player's &Name", name_inputs[i]);
  }



  mainLayout->addLayout (fl);

  setLayout (mainLayout);
   
  show();
}


// void Qboard::W1confirm(QString* n, int players )
// {

//   names = n;
//   number_of_players = players;
//   std::cout<<"SIZE OF NAMES ISRYTKRT :"<<number_of_players<<std::endl;
//   std::cout<<"NAMES ARE :"<<std::endl;
// //ARRAY OF NAMES IS NOT BEING RECEIVED



//   for(int i = 0; i< number_of_players; i++)
//   {
//     std::cout<<names[i].toStdString()<<std::endl;

//   }

//   allNameLabels = new QLabel* [number_of_players];
//   QFormLayout *fl = new QFormLayout;


//   for(int i = 0; i< number_of_players; i++)
//   {

//     allNameLabels[i]->setText(names[i]);   
//     fl->addRow ("Player's name", allNameLabels[i]);
//   }

//   mainLayout->addLayout (fl);

//   setLayout (mainLayout);


//   show();

// }


void Qboard::quitPressed ()
{
  std::cout << "Quit was pressed!\n";
  close ();
}
