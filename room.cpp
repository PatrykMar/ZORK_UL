#include <sstream>
#include <QString>
#include <algorithm>
#include "Room.h"
#include "battle.h"
using namespace std;

Room::Room(string newName) : name(newName), enemyInRoom(NULL), foundExit(false){}

Room::Room(string newName,Item *item){
    name = newName;
    itemsInRoom.push_back(item);
    foundExit = false;
}

Room::~Room(){
    delete enemyInRoom;

    for(unsigned int i = 0;i<itemsInRoom.size();i++){
        delete itemsInRoom[i];
    }
}

void Room::setExits(Room *north,Room *south,Room *east,Room *west) {
    if(north != NULL)
        exits["north"] = north;
    if(south != NULL)
        exits["south"] = south;
    if(east != NULL)
        exits["east"] = east;
    if(west != NULL)
        exits["west"] = west;
}

string Room::getName(){
    return name;
}

Room* Room::nextRoom(string direction){
    map<string, Room*>::iterator next = exits.find(direction);
    if(next ==exits.end())
        return NULL;
    return next->second;
}

void Room::addItem(Item *inItem) {
    itemsInRoom.push_back(inItem);
}

string Room::displayItem(){
    string items;
    int sizeItems = itemsInRoom.size();
    if (sizeItems < 1) {
        items = "There are no items in this room.\n";
    }
    else {
        items =  "Items in room:\n";
        for (int n = 0; n < sizeItems; n++) {
            items += " - " + itemsInRoom[n]->getName() + "\n";
        }
    }
    return items;
}

int Room::numOfItems() {
    return itemsInRoom.size();
}

int Room::getItemIndexByName(string itemName) { //used for getItemByName
    int index = 0;
    int size = itemsInRoom.size();
    for(int i = 0; i < size; i++) {
        //if (0 == itemName.compare(itemsInRoom[i]->getName())) {
        if ((*itemsInRoom[i]) == itemName) {
            index = i;
        }
    }
    return index;
}

Item* Room::getItemByName(string itemName) { //used
    int index = getItemIndexByName(itemName);
    return itemsInRoom[index];
}

void Room::addMonster(Enemy *ene){
    this->enemyInRoom = ene;
}

Enemy* Room::getEnemyInRoom() const{
    return enemyInRoom;
}

void Room::deleteMonsterInRoom(){
    delete this->enemyInRoom;
}

vector <Item*> Room::getItemsInRoom()const{
    return itemsInRoom;
}

void Room::removeItem(Item *item){
    itemsInRoom.erase( std::remove(itemsInRoom.begin(), itemsInRoom.end(), item), itemsInRoom.end());
}

void Room::setNullMonster(){
    this->enemyInRoom = NULL;
}

void Room::setLast(){
    this->foundExit = true;
}

bool Room::getLast()const{
    return this->foundExit;
}
