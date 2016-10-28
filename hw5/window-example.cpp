#include <QApplication>
#include "NumberWindow.h"
#include<iostream>
int main (int argc, char *argv[])
{
  QApplication app (argc, argv);
  NumberWindow w[3];
  for(int i = 0; i<3;i++)
  {
  	w[i].set_window_number(i);
  }

  //ipln(0);
  //ipln.show();
  w[0].show();
  std::cout<<"executed window 0"<<std::endl;
  //NumberWindow opln1(1);
 // opln1.set_window_number();

  QObject::connect (&w[0], SIGNAL(W0(/*QString ,*/int )),&w[1],SLOT(W0confirmPressed (/*QString ,*/int)));
  std::cout<<"executed window 1"<<std::endl; 

 // NumberWindow opln2(2);
  //opln2.set_window_number(2);
  //QObject::connect (&w[1], SIGNAL(W2send(QString*, int )),&w[2],SLOT(W1confirm (QString*, int)));

  std::cout<<"executed window 2"<<std::endl;

  app.exec ();

  return 0;
}
