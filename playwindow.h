#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QToolBar>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QComboBox>
#include <QString>
#include "ZorkUL.h"
//#include "finalwindow.h"
//#include "battle.h"

using namespace std;
namespace  Ui{
class PlayWindow;
}

class PlayWindow : public QMainWindow
{
    Q_OBJECT
public:
    ~PlayWindow();
    explicit PlayWindow(QWidget *parent = 0);
    void setName(std::string userName);
    string getCommand();
    void setup(string UserName);
};

#endif // PLAYWINDOW_H
