#ifndef CHARINFOWINDOW_H
#define CHARINFOWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <string>
#include "playwindow.h"
using namespace std;
namespace Ui {
    class CharInfoWindow;

}

    class CharInfoWindow : public QMainWindow
    {
        Q_OBJECT

     public:
        explicit CharInfoWindow(QWidget *parent = 0);
        string getName();
        ~CharInfoWindow();

    private slots:
        void submitHandler();
        bool validateText(QString toValidate);

    private:
        PlayWindow *playWin;
        QGridLayout *txtLayout;
        QLineEdit *nameBox;
        QLineEdit *surBox;
        QPushButton *submitButton;
        QLabel *askName;
        QLabel *error;
        string name;
    };
#endif // CHARINFOWINDOW_H
