#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "charinfowindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startHandler();
    void exitHandler();

private:
    QPushButton *startButton;
    QPushButton *exitButton;
    CharInfoWindow *ciWin;

};

#endif // MAINWINDOW_Hs
