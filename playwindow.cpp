#include <iostream>
#include <QCoreApplication>
#include <QApplication>
#include <QLabel>
#include <QDir>
#include <QComboBox>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QRadioButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QComboBox>
#include <QString>
#include <QToolBar>
#include <QSignalMapper>
#include "playwindow.h"
#include "charinfowindow.h"
#include "zorkul.h"

using namespace std;

#define PATH QDir::currentPath()

PlayWindow::PlayWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setCentralWidget(new QWidget());
    m_layout = new QVBoxLayout();
    (this->centralWidget())->setLayout(m_layout);
    m_layout->setSpacing(0);

    toolBar = new QToolBar();

    healthBoost = 10;
    showMap = 0;
    map = new QLabel(this);

    QPixmap pixmap(PATH + "/map.png");
    map->setPixmap(pixmap);
    map->setGeometry(QRect(QPoint(0,250),QSize(350,300)));

    inventory = new QComboBox;
    inventory->addItem("Inventory");
    inventory->addItem("Fist");
    inventory->setMinimumWidth(180);
    mapButton = new QPushButton("Map", this);
    mapButton->setMinimumWidth(180);
    quitButton = new QPushButton("Quit", this);
    quitButton->setMinimumWidth(180);

    toolBar->addWidget(inventory);
    toolBar->addWidget(mapButton);
    toolBar->addWidget(quitButton);

    itemBox = new QComboBox;
    toolBar->addWidget(itemBox);
    itemBox->setMinimumWidth(180);

    toolBar ->setFloatable(false);
    toolBar ->setMovable(false);
    toolBar -> show();

    m_layout->setMenuBar(toolBar);

    rButtons = new QGroupBox("Pick a weapon!");
    rLayout = new QVBoxLayout();

    fist = new QRadioButton(tr("Fist"));
    fist->setChecked(false);

    sword = new QRadioButton(tr("Sword"));
    sword->setChecked(false);

    knife = new QRadioButton(tr("Knife"));
    knife->setChecked(false);

    axe = new QRadioButton(tr("Axe"));
    axe->setChecked(false);

    rLayout -> addWidget(fist);
    rLayout -> addWidget(sword);
    rLayout -> addWidget(knife);
    rLayout -> addWidget(axe);

    rButtons->setLayout(rLayout);
    m_layout->addWidget(rButtons);

    upButton = new QPushButton("Up", this);
    upButton->setGeometry(QRect(QPoint(400, 500),QSize(50, 50)));
    leftButton = new QPushButton("Left", this);
    leftButton->setGeometry(QRect(QPoint(350, 525),QSize(50, 50)));
    downButton = new QPushButton("Down", this);
    downButton->setGeometry(QRect(QPoint(400, 550),QSize(50, 50)));
    rightButton = new QPushButton("Right", this);
    rightButton->setGeometry(QRect(QPoint(450, 525),QSize(50, 50)));

    attackButton = new QPushButton("Attack!", this);
    takeButton = new QPushButton("Take", this);
    weaponButton = new QPushButton("Use this weapon", this);
    takeButton->setMaximumWidth(100);
    attackButton->setMaximumWidth(100);
    weaponButton->setMaximumWidth(100);

    name = new QLabel(this);
    health = new QLabel(this);
    currRoom = new QLabel(this);
    roomDesc = new QLabel(this);
    textDesc = new QLabel(this);
    enemyDead = new QLabel(this);
    enemyHealth = new QLabel(this);

    QString monText = QString::fromStdString("You have killed the monster!");
    enemyDead->setText(monText);

    m_layout->addWidget(weaponButton);
    m_layout->addWidget(name);
    m_layout->addWidget(currRoom);
    m_layout->addWidget(textDesc);
    m_layout->addWidget(roomDesc);
    m_layout->addWidget(health);
    m_layout->addWidget(enemyDead);
    m_layout->addWidget(enemyHealth);
    m_layout->addWidget(attackButton);
    m_layout->addWidget(takeButton);

    QSignalMapper *signalMapperWeapon = new QSignalMapper(this);
    QSignalMapper *signalMapperDirection = new QSignalMapper(this);

    connect(mapButton, SIGNAL (clicked()), this, SLOT (mapHandler()));
    connect(quitButton, SIGNAL (clicked()), this, SLOT (quitHandler()));
    connect(leftButton, SIGNAL (clicked()), signalMapperDirection, SLOT (map()));
    connect(rightButton, SIGNAL (clicked()), signalMapperDirection, SLOT (map()));
    connect(upButton, SIGNAL (clicked()), signalMapperDirection, SLOT (map()));
    connect(downButton, SIGNAL (clicked()), signalMapperDirection, SLOT (map()));
    connect(attackButton, SIGNAL (clicked()), this, SLOT (attackHandler()));
    connect(takeButton, SIGNAL (clicked()), this, SLOT (takeHandler()));
    connect(weaponButton, SIGNAL (clicked()), this, SLOT (weaponHandler()));
    connect(fist, SIGNAL (toggled(bool)), signalMapperWeapon, SLOT (map()));
    connect(sword, SIGNAL (toggled(bool)), signalMapperWeapon, SLOT (map()));
    connect(knife, SIGNAL (toggled(bool)), signalMapperWeapon, SLOT (map()));
    connect(axe, SIGNAL (toggled(bool)), signalMapperWeapon, SLOT (map()));

    signalMapperDirection->setMapping(leftButton, "west");
    signalMapperDirection->setMapping(rightButton, "east");
    signalMapperDirection->setMapping(upButton, "north");
    signalMapperDirection->setMapping(downButton, "south");
    signalMapperWeapon->setMapping(fist, "Fist");
    signalMapperWeapon->setMapping(sword, "Sword");
    signalMapperWeapon->setMapping(knife, "Knife");
    signalMapperWeapon->setMapping(axe, "Axe");


    connect(signalMapperDirection, SIGNAL(mapped(QString)), this, SLOT(directionSelected(QString)));
    connect(signalMapperWeapon, SIGNAL(mapped(QString)), this, SLOT(weaponSelected(QString)));
}

void PlayWindow::mapHandler() {
    cout << "hey" << endl;
    if(0 == showMap) {
        map->show();
        showMap = 1;
    }
    else {
        map->hide();
        showMap = 0;
    }
}

void PlayWindow::quitHandler() {
    QApplication::quit();
}

void PlayWindow::directionSelected(QString direction) {
    playGame->goRoom(direction.toStdString());
    setRoom();
}

void PlayWindow::takeHandler() {
    if (playGame->currentRoom->numOfItems() > 0){
        string itemName = (itemBox->currentText()).toStdString();
        Item *temp = (playGame->getCurrentRoom())->getItemByName(itemName);
        (playGame->getPlayer())->addItem(temp);
        (playGame->getCurrentRoom())->removeItem(temp);
        setRoom();
        playGame->getPlayer()->addItem(temp);
        inventory->addItem(QString::fromStdString(itemName));
    }
}

void PlayWindow::attackHandler() {
    if(playGame->me->getHealth() != 0 && playGame->currentRoom->getEnemyInRoom()->getHealth() != 0){
        battle->engageBattle(playGame);
        enemyHealth->show();
    }
    enemyHealth->setText("Monster Health: " + QString::number(playGame->currentRoom->getEnemyInRoom()->getHealth()));
    setHealth(playGame->me->getHealth());
    if(playGame->currentRoom->getEnemyInRoom()->getHealth() <= 0){
        playGame->currentRoom->deleteEnemyInRoom();
        playGame->currentRoom->setNullEnemy();
        attackButton->hide();
        enemyHealth->hide();
        enemyDead->show();
        showDirectionalButtons();
        delete battle;
    }
    else if(playGame->me->getHealth() <= 0){
        string message = "You have no health left! GAME OVER";
        showFinalWindow(message);
    }
}

void PlayWindow::weaponHandler(){
    QString weapon;
    if (fist->isChecked()){
            weapon = "Fist";
    }
    else if (sword->isChecked()) {
        weapon = "Sword";
    }
    else if (knife->isChecked()) {
        weapon = "Knife";
    }
    else if (axe->isChecked()){
        weapon = "Axe";
    }
    weaponSelected(weapon);
    rButtons->hide();
    weaponButton->hide();
    enemyHealth->setText("Monster Health: " + QString::number(playGame->currentRoom->getEnemyInRoom()->getHealth()));
    enemyHealth->show();
    attackButton->show();
}

PlayWindow::~PlayWindow() {
    delete m_layout;
    delete inventory;
    delete mapButton;
    delete leftButton;
    delete upButton;
    delete rightButton;
    delete downButton;
    delete quitButton;
    delete attackButton;
    delete takeButton;
    delete playGame;
    delete name;
    delete health;
    delete currRoom;
    delete roomDesc;
    delete enemyDead;
    delete weaponButton;
    delete fist;
    delete knife;
    delete sword;
    delete axe;
    delete itemBox;
    delete map;
    delete rButtons;
    delete toolBar;
}

void PlayWindow::setName(string userName) {
    string nameText = "Name: " + userName;
    name->setText(QString::fromStdString(nameText));
}

void PlayWindow::setRoom() {
    string roomText = "Room: " + playGame->currentRoom->getName();
    string textDescription = "Description: " + playGame->currentRoom->getText();
    currRoom->setText(QString::fromStdString(roomText));
    textDesc->setText(QString::fromStdString(textDescription));
    roomDesc->setText(QString::fromStdString(playGame->currentRoom->displayItem()));
    displayRoomItems();
    showDirectionalButtons();
    enemyDead->hide();
    if((playGame->getCurrentRoom())->getEnemyInRoom() != nullptr){
        battle = new Battle();
        hideDirectionalButtons();
        setRadioButtons();
    }
    else if(playGame->currentRoom->getLast() == true){
        string message = "You push past the large wooden doors and out into the world, to freedom! The light blinds you as you leave. \nYou look around in disbelief. This is not the world you remember. Who are you? And what happened while you were gone...";
        showFinalWindow(message);
    }
}

void PlayWindow::setHealth(int newHealth) {
    QString healthText = QString::fromStdString("Health: ") + QString::number(newHealth);
    health->setText(healthText);
}

void PlayWindow::setup(string userName) {
    playGame = new ZorkUL(userName);
    setName(userName);
    setHealth(playGame->me->getHealth());
    showDirectionalButtons();
    setRoom();
    hideButtons();
}

void PlayWindow::setRadioButtons(){
    vector <Item*> items = (playGame->getPlayer())->getItemsInChar();
    for(vector<Item*>::iterator it = items.begin(); it != items.end(); it++){
        Item *item = *it;
        if(item->getCheckWeapon() != false){
           if(*item == "Fist"){
                fist->show();
            }
           else if(*item == "Sword"){
                sword->show();
            }
           else if(*item == "Knife"){
               knife->show();
           }
           else if(*item == "Axe"){
               axe->show();
           }
        }
    }
   rButtons->show();
   weaponButton->show();
}

void PlayWindow::displayRoomItems(){
    itemBox->clear();
    vector <Item*> itemList = (playGame->getCurrentRoom())->getItemsInRoom();
    if(itemList.size() > 0){
        takeButton->show();
            for(vector<Item*>::iterator it = itemList.begin(); it != itemList.end(); ++it){
            string name = (*it)->getName();
            itemBox->addItem(QString::fromStdString(name));
        }
    }
    else{
        takeButton->hide();
        itemBox->addItem("No items in Room");
    }
}

void PlayWindow::hideDirectionalButtons() {
    upButton->hide();
    downButton->hide();
    leftButton->hide();
    rightButton->hide();
}

void PlayWindow::showDirectionalButtons() {
    upButton->show();
    downButton->show();
    leftButton->show();
    rightButton->show();
}

void PlayWindow::hideButtons(){
    attackButton->hide();
    weaponButton->hide();
    takeButton->hide();
    rButtons->hide();
    map->hide();
    sword->hide();
    enemyDead->hide();
    knife->hide();
    fist->hide();
    axe->hide();
}

void PlayWindow::weaponSelected(QString qweapon) {
    string weapon = qweapon.toStdString();
    vector<Item*> items = playGame->me->getItemsInChar();
    for(std::vector<Item*>::iterator it = items.begin();
        it != items.end(); it++) {
        Item *temp = *it;
        if((*temp) == weapon) {
            playGame->me->setCurrentItem(*temp);
        }
    }
}

void PlayWindow::showFinalWindow(string message){
    fw = new FinalWindow;
    fw->setMinimumSize(400, 400);
    fw->setMessage(message);
    close();
    fw->show();
}
