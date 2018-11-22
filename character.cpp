#include "character.h"

using std::string;

Character::Character(){}

Character::~Character(){}

Character::Character(string name,string desc,int health,int strength,double hitChance) : name(name),desc(desc),health(health)
  ,strength(strength),hitChance(hitChance){}

string Character::getName()const{
    return this->name;
}

string Character::getDesc()const{
    return this->desc;
}

int Character::getStrength()const{
    return this->strength;
}

double Character::getHitChance()const{
    return this->hitChance;
}

int Character::getHealth()const{
    return this->health;
}

void Character::setHealth(int newHealth){
    this->health = newHealth;
}
