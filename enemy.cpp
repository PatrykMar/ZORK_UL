#include "enemy.h"
using namespace std;

Enemy::Enemy(){}

Enemy::~Enemy(){}

Enemy::Enemy(string newName,string enemyDesc,int newHealth,int strength,double newHitChance)
    : Character(newName,enemyDesc,newHealth,strength,newHitChance){}
