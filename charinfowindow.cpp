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
    txtLayout = new QGridLayout();
    this->centralWidget()->setLayout(txtLayout);

    error = new QLabel("");
    askName = new QLabel("Nickname:");
    nameBox = new QLineEdit();
    submitButton = new QPushButton("Submit");

    txtLayout->addWidget(error,0,0,0,0);
    txtLayout->addWidget(askName,0,0,1,1);
    txtLayout->addWidget(nameBox,0,1,1,1);
    txtLayout->addWidget(submitButton,3,0,1,4);

    QString qName = nameBox->text();

    connect(submitButton,SIGNAL (clicked()),this,SLOT(submitHandler()));

}

void CharInfoWindow::submitHandler()
{
  if(validateText(nameBox->text()))
  {
      name = nameBox->text().toStdString();
      close();

      playWin = new PlayWindow;
      playWin->setFixedSize(800,600);
      playWin->setup(name);
      playWin ->show();
  }
  else if(!validateText((nameBox->text())))
  {
      error->setText("Input must be alphabetic.");
  }
  else
  {
    error->setText("Invalid input.");
  }
}

bool CharInfoWindow::validateText(QString toValidate)
{
    bool valid = false;

    QRegExp val("[A-Za-z}");
    QRegExpValidator validator(val,0);
    int pos = 0;
    string validText;

    if(validator.validate(toValidate,pos) && 0 != toValidate.compare(""))
    {
        valid = true;
    }
    return valid;
}

CharInfoWindow::~CharInfoWindow()
{
    delete txtLayout;
    delete nameBox;
    delete submitButton;
    delete askName;
    delete error;
}
