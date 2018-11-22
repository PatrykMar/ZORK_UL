#ifndef ROOM_H
#define ROOM_H

#include <map>
#include <QString>
#include <string>
#include <vector>
#include <QPushButton>
#include "item.h"
#include "enemy.h"

using namespace std;

class Room{

private:
    string name;
    string text;
    map<string,Room*> exits;
    string exitString();
    vector <Item*> itemsInRoom;
    Enemy *enemyInRoom;
    bool foundExit;

public:
    ~Room();
    int numOfItems();
    Room(string description,Item *item);
    Room(string description);
    Room(string description,string text);
    void setExits(Room *north,Room *south,Room *east,Room *west);
    string getName();
    Room* nextRoom(string direction);
    void addItem(Item *inItem);
    string displayItem();
    string getItems();
    int getItemIndexByName(string itemName);
    Item* getItemByName(string itemName);
    void addEnemy(Enemy *Enemy);
    Enemy* getEnemyInRoom() const;
    void deleteEnemyInRoom();
    vector <Item*> getItemsInRoom()const;
    void removeItem(Item *item);
    void setNullEnemy();
    void setLast();
    bool getLast()const;
    void setText(string text);
    string getText()const;
};
#endif // ROOM_H
