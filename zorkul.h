#ifndef ZORKUL_H
#define ZORKUL_H


#include <string>
#include "character.h"
#include "player.h"
#include "room.h"

using namespace std;

class ZorkUL{
    friend class PlayWindow;
private:
    Room *currentRoom;
    vector <Room*> roomList;
    void createRooms();
    void goRoom(string direction);
    Player *me;

public:
    ZorkUL(string name);
    ~ZorkUL();
        void play();
    Room* getCurrentRoom() const;
    Player* getPlayer() const;
};

#endif // ZORKUL_H
