#include "battle.h"
#include "character.h"
#include "zorkul.h"
#include <random>
#include <QApplication>

Battle::Battle(){}

void Battle::engageBattle(ZorkUL *playGame){
    Player *me = playGame->getPlayer();
    Room *room = playGame->getCurrentRoom();
    Enemy *ene = room->getEnemyInRoom();

    double hit ((double)rand()/(RAND_MAX + 1.0));

    int monsterStrength = ene->getStrength();
    int playerStrength = me->getStrength();

    if(me->getCurrentItem()=="Fist"){
        playerStrength = 1;
    }
    else if(me->getCurrentItem()=="Sword"){
        playerStrength = 3;
    }
    else if(me->getCurrentItem()=="Knife"){
        playerStrength = 2;
    }
    else if(me->getCurrentItem()=="Axe")
    {
        playerStrength = 5;
    }



    int myHealth = me->getHealth();
    int eneHealth = ene->getHealth();

    if(hit <=me->getHitChance()){
        ene->setHealth(eneHealth-playerStrength);
    }
    if(hit >= ene->getHitChance()){
        me->setHealth(myHealth-monsterStrength);
    }
  }
    void Battle::endGame(){
        QApplication::quit();
    }

    Battle::~Battle(){}


