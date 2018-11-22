#include <QInputDialog>
#include <QLineEdit>
#include <QCoreApplication>
#include <QWidget>
#include <QMainWindow>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ciWin = new CharInfoWindow;
    startButton = new QPushButton("Start", this);
    startButton->setGeometry(QRect(QPoint(100, 100),QSize(200, 50)));

    exitButton = new QPushButton("Exit", this);
    exitButton->setGeometry(QRect(QPoint(100, 200),QSize(200, 50)));


    connect(startButton, SIGNAL (clicked()), this, SLOT (startHandler()));
    connect(exitButton, SIGNAL (clicked()), this, SLOT (exitHandler()));
}

void MainWindow::startHandler()
{
    ciWin->setFixedSize(400,400);
    ciWin->show();
    close();
}

void MainWindow::exitHandler()
{
    QCoreApplication::quit();
}

MainWindow::~MainWindow() {
    delete startButton;
    delete exitButton;
    delete ciWin;
}
