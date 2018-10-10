#include "zorkul.h"
#include "playwindow.h"

ZorkUL::ZorkUL(string name){
    me = new Player(name, 10, .75);
    createRooms();
}

void ZorkUL::createRooms()  {
//This function creates all the rooms, objects and monsters in the game
    Item *sword = new Item("Sword", true);

    Room *one, *two, *three;
    one = new Room("one");
    two = new Room("two");
    three = new Room("three");

    roomList.push_back(one);
    roomList.push_back(two);
    roomList.push_back(three);
    three -> setLast();

    one->addItem(sword);
    two->addEnemy(new Enemy("Enemy",10,.80));
               //north,south,east,west
    one->setExits(NULL,two,NULL,NULL);
    two->setExits(one,NULL,three,NULL);
    currentRoom = one;
}

void ZorkUL::goRoom(string direction){
    // This function moves the current room pointer to the next room,
    // depending on the string direction passed to it
        Room* nextRoom = currentRoom->nextRoom(direction);
        if (nextRoom != NULL){
            currentRoom = nextRoom;
        }
}

Room* ZorkUL::getCurrentRoom()const{
    return this->currentRoom;
}

Player* ZorkUL::getPlayer()const{
    return this->me;
}

ZorkUL::~ZorkUL(){
    delete me;
    delete currentRoom;

    for(unsigned int i =0;i<roomList.size();i++){
        delete roomList[i];
    }
}
