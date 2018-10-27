#ifndef ROOM_H
#define ROOM_H

#include <map>
#include <QString>
#include <string>
#include <vector>
#include <QPushButton>
#include "item.h"
#include "enemy.h"

class Room{

private:
    std::string name;
    std::map<std::string,Room*> exits;
    std::string extiString();
    std::vector <Item*> itemsInRoom;
    Enemy *enemyInRoom;
    bool foundExit;

public:
    ~Room();
    int numOfItems();
    Room(std::string description,Item *item);
    Room(std::string description);
    void setExits(Room *north,Room *south,Room *east,Room *west);
    std::string getName();
    Room* nextRoom(std::string direction);
    void addItem(Item *inItem);
    std::string displayItem();
    std::string getItems();
    int getItemIndexByName(std::string itemName);
    Item* getItemByName(std::string itemName);
    void addEnemy(Enemy *Enemy);
    Enemy* getEnemyInRoom() const;
    void deleteEnemyInRoom();
    std::vector <Item*> getItemsInRoom()const;
    void removeItem(Item *item);
    void setNullEnemy();
    void setLast();
    bool getLast()const;
};
#endif // ROOM_H
