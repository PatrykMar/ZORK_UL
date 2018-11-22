#include <sstream>
#include <QString>
#include <algorithm>
#include "room.h"
#include "battle.h"
using namespace std;

Room::Room(string newName) : name(newName), enemyInRoom(nullptr), foundExit(false){}

Room::Room(string newName,Item *item){
    name = newName;
    itemsInRoom.push_back(item);
    foundExit = false;
}

Room::Room(string newName,string newText){
    name = newName;
    text = newText;
}


Room::~Room(){
    delete enemyInRoom;

    for(unsigned int i = 0;i<itemsInRoom.size();i++){
        delete itemsInRoom[i];
    }
}

void Room::setExits(Room *north,Room *south,Room *east,Room *west) {
    if(north != nullptr)
        exits["north"] = north;
    if(south != nullptr)
        exits["south"] = south;
    if(east != nullptr)
        exits["east"] = east;
    if(west != nullptr)
        exits["west"] = west;
}

string Room::getName(){
    return name;
}

Room* Room::nextRoom(string direction){
    map<string, Room*>::iterator next = exits.find(direction);
    if(next == exits.end())
        return nullptr;
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

void Room::addEnemy(Enemy *ene){
    this->enemyInRoom = ene;
}

Enemy* Room::getEnemyInRoom() const{
    return enemyInRoom;
}

void Room::deleteEnemyInRoom(){
    delete this->enemyInRoom;
}

vector <Item*> Room::getItemsInRoom()const{
    return itemsInRoom;
}

void Room::removeItem(Item *item){
    itemsInRoom.erase( std::remove(itemsInRoom.begin(), itemsInRoom.end(), item), itemsInRoom.end());
}

void Room::setNullEnemy(){
    this->enemyInRoom = nullptr;
}

void Room::setLast(){
    this->foundExit = true;
}

bool Room::getLast()const{
    return this->foundExit;
}

void Room::setText(string text){
    this->text = text;
}

string Room::getText()const{
    return this->text;
}
