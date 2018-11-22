#ifndef ENEMY_H
#define ENEMY_H
#include "character.h"
using namespace std;

class Enemy : public Character
{
public:
    Enemy();
    Enemy(string newName,string enemyDesc,int newHealth,int strength,double newHitChance);
    ~Enemy();
};
#endif // ENEMY_H
