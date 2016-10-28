#include <QApplication>
#include "SButton.h"
#include <iostream>
int main (int argc, char *argv[])
{
  QApplication app (argc, argv);
  SButton s1(0, 0, "...");



  std::cout<<"executed window 0"<<std::endl;


  return app.exec ();
}