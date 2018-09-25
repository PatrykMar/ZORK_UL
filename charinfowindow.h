#ifndef CHARINFOWINDOW_H
#define CHARINFOWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <string>
//need to include header with the game window

namespace Ui {
    class CharInfoWindow;

}

    class CharInfoWindow : public QMainWindow
    {
        Q_OBJECT

     public:
        explicit CharInfoWindow(QWidget *parent = 0);
        string getName();
        string getSur();
        ~CharInfoWindow();

    private slots:
        void submitHandler();
        bool validateText(QString toValidate);

    private:
        QGridLayout *txtlayout;
        QLineEdit *nameBox;
        QLineEdit *surBox;
        QPushButton *submitButton;
        QLabel *askName;
        QLabel *askSur;
        QLabel *error;
        string name;
        string sur;
    }

#endif // CHARINFOWINDOW_H
