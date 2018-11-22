#include "zorkul.h"
#include "playwindow.h"

ZorkUL::ZorkUL(string name){
    me = new Player(name, "", 40, 0, .60);
    createRooms();
}

void ZorkUL::createRooms()  {
//This function creates all the rooms, objects and monsters in the game
    Item *fist = new Item("Fist", true);
    Item *sword = new Item("Sword", true);
    Item *knife = new Item("Knife", true);
    Item *axe = new Item("Axe", true);

    me->addItem(fist);

    Room *one, *two, *three,*four,*five,*six,*seven,*eight,*nine,*ten,*eleven,*twelve,*thirteen,*fourteen,*fifteen,*sixteen;
    one = new Room("one","You wake up, vision hazy and head dizzy. You find yourself in a dark, grim room. You hear scampering in the distance.\nThere seems to be only one exit, to the north.");
    two = new Room("two","You enter a very poorly lit sqaure chamber. All of the walls are grey stone and it is eerily cold. \nThere are hallways to the north, south, east and west.");
    three = new Room("three","Another chamber quite similar to the previous. There seems to only be exits to the east and the west. \nYou feel a chill and the sudden urge to leave.");
    four = new Room("four","A very cold chamber. You see water trickling down one of the walls. You're certain that this place is underground. \nThere are exits to the north and the east.");
    five = new Room("five","All of the chambers are merging into one. An almost identical room. You wonder how long it'll take for you to go insane. \nThere are hallways to the south and the west.");
    six = new Room("six","You swear you've been in this room before. Although, you could say that about all the rooms. \nThere are exits to the south and the east.");
    seven = new Room("seven","Yet another chamber. Your spirits are starting to waver. Suddenly, the walls tremble! Time to go. \nThere are hallways to the south and the west.");
    eight = new Room("eight","Your stomach rumbles. If you aren't killed by the monsters in here, you know you'll die eventually. \nThere are exits to the north and the south.");
    nine = new Room("nine","Guess what? Another. Chamber. This is a very poorly designed dungeon. No passion. Disappointing. \nThere are hallways to the north and the west.");
    ten = new Room("ten","You hear clacking and deep breathing. Rather unnerving. You swear you can hear chirping also. \nThere are exits to the north, east and west.");
    eleven = new Room("eleven","This chamber is different to the others. There are no obvious exits but there are two small spaces\nyou could possibly fit through.");
    twelve = new Room("twelve","The sound of chirping increases but you still hear that deep breathing. \nThere are exits to the south and the east.");
    thirteen = new Room("thirteen","Down another hallway, twisting almost further down. The breathing is very distinct now. \n There are hallways to the north and the west.");
    fourteen = new Room("fourteen","You turn the corner, into what must be one of the final chambers and are faced with an ugly troll. \nYour final test. Defeat it and south to your freedom!");
    fifteen = new Room("fifteen");
    sixteen = new Room("sixteen","Congratulations! You have found the hidden easter egg! Your reward? Being trapped for eternity! \nIf only I could restart this.... (Hit Exit and start over)");


    roomList.push_back(one);
    roomList.push_back(two);
    roomList.push_back(three);
    roomList.push_back(four);
    roomList.push_back(five);
    roomList.push_back(six);
    roomList.push_back(seven);
    roomList.push_back(eight);
    roomList.push_back(nine);
    roomList.push_back(ten);
    roomList.push_back(eleven);
    roomList.push_back(twelve);
    roomList.push_back(thirteen);
    roomList.push_back(fourteen);
    roomList.push_back(fifteen);
    roomList.push_back(sixteen);
    fifteen -> setLast();

    two->addItem(knife);
    three->addEnemy(new Enemy("Ghoul","If death had a baby, it would look like this creature. Small, ugly and ravenous.",10,2,.40));
    four->addEnemy(new Enemy("Goblin","Green abomination. Little to no threat.",5,2,.60));
    six->addItem(sword);
    eleven->addEnemy(new Enemy("Skeleton","What you would look like after rotting away for hundreds of years. Dangerous if not dealt with quickly.",5,3,.10));
    eleven->addItem(axe);
    //twelve->addItem(healthElixir);
    fourteen->addEnemy(new Enemy("Troll","Big. Angry. Big. Avoid unless absolutely necessary.",25,4,.50));

               //north,south,east,west
    one->setExits(two,nullptr,nullptr,nullptr);
    two->setExits(five,one,three,four);
    three->setExits(sixteen,nullptr,seven,two);
    four->setExits(six,nullptr,two,nullptr);
    five->setExits(nullptr,two,nullptr,six);
    six->setExits(nullptr,four,five,nullptr);
    seven->setExits(nullptr,eight,nullptr,three);
    eight->setExits(seven,nine,nullptr,nullptr);
    nine->setExits(eight,nullptr,nullptr,ten);
    ten->setExits(eleven,nullptr,nine,twelve);
    eleven->setExits(nullptr,ten,eight,one);
    twelve->setExits(nullptr,thirteen,ten,nullptr);
    thirteen->setExits(twelve,nullptr,nullptr,fourteen);
    fourteen->setExits(nullptr,fifteen,thirteen,nullptr);

    currentRoom = one;
}

void ZorkUL::goRoom(string direction){
    // This function moves the current room pointer to the next room,
    // depending on the string direction passed to it
        Room* nextRoom = currentRoom->nextRoom(direction);
        if (nextRoom != nullptr){
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
