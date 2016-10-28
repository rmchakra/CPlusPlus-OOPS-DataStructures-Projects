#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QCloseEvent>
#include <QObject>
#include <QLabel>
#include <QString>

class Qboard : public QWidget
{
  Q_OBJECT

    public:
    Qboard (Board& board, QWidget *parent = 0);














    

    void closeEvent (QCloseEvent *event);
    int get_window_number(){return window_number;}
    void set_window_number(int a = 1);
    //set_window_number also makes changes

    signals:
    void  W0(/*QString name, */int players);
   // void W2send(QString* names, int players);

    public slots:
    void confirmPressed ();
    void quitPressed ();
    void W0confirmPressed (/*QString name = "no input",*/ int players);
    //void W1confirm(QString* n, int players);
    QString* get_names(){return names;}
    void set_names(QString n[]){names=n;}


 private:
    Board& mb;//this is my board




    QPushButton *quitButton, *confirmButton;
    //QLineEdit *name;
    QSpinBox *number;
    QLabel* nameLabel;
    QLabel* numberLabel;
    QVBoxLayout *mainLayout;
    QLineEdit **name_inputs;
    QLabel** allNameLabels; 
    int window_number;
    int number_of_players;
    QString* names;

};
