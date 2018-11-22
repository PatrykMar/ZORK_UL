#ifndef FINALWINDOW_H
#define FINALWINDOW_H


#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

using std::string;

class FinalWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit FinalWindow(QWidget *parent = nullptr);
    ~FinalWindow();
    void setMessage(string message);
    string getMessage()const;

    signals:

private slots:
    void quitHandler();

private:
    QVBoxLayout *layout;
    QLabel *endMessage;
    QPushButton *quitButton;
    string message;
};

#endif // FINALWINDOW_H
