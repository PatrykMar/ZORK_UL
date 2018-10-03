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

    double hit ((double)rand()/(RAND_MAX));

    int monsterStrength = 1;
    int playerStrength = 1;

    if(me->getCurrentItem()=="Sword"){
        monsterStrength = 2;
        playerStrength = 4;
    }

    int myHealth = me->getHealth();
    int eneHealth = ene->getHealth();

    if(hit <=me->getHitChance()){
        ene->setHealth(eneHealth-playerStrength);
    }
    if(hit >= ene->getHitChance()){
        me->setHealth(myHealth-monsterStrength);
    }
    if(me->getHealth()<=0){
        endGame();
    }
  }
    void Battle::endGame(){
        QApplication::quit();
    }

    Battle::~Battle(){}


