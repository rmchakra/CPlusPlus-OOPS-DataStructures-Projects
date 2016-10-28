#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QString>
class SButton : public QPushButton {

  Q_OBJECT

public:
    SButton(int row_number, int column_number, std::string c, QWidget *parent = 0);
    int return_row(){return row;}
    int return_row(){return col;}
  

  signals:
  void pos(int a, int b);

    
  public slots:
  //setEnabled(false) makes it unclickable
  void emits_pos();

  
  //below is for placing the letters on it
  void placed_letter_pts(/*std::string l = "N3 "*/);


  


private:
    int row, col;
};