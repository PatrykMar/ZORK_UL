#include <QCoreApplication>
#include <QLineEdit>
#include <QRegExpValidator>
#include <QValidator>
#include "charinfowindow.h"

using namespace std;

CharInfoWindow::CharInfoWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setCentralWidget(new QWidget());
    textLayout = new QGridLayout();
    this->centralWidget()->setLayout(textLayout);


}
