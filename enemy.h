#ifndef ENEMY_H
#define ENEMY_H
#include "character.h"

class Enemy : public Character
{
public:
    Enemy();
    Enemy(std::string newName,int newHealth, double newHitChance);
    ~Enemy();
};
#endif // ENEMY_H
