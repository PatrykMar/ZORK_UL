#include <vector>
#include "player.h"
#include "item.h"
using namespace std;
Player::Player(){}

Player::Player(string newName,string desc,int newHealth,int strength,double newHitChance) :
    Character(newName,desc,newHealth,strength,newHitChance) { }

Player::~Player(){

}

std::vector <Item*> Player::getItemsInChar()const{
    return itemsInChar;
}

void Player::addItem(Item *item){
    itemsInChar.push_back(item);
}

void Player::setCurrentItem(Item item){
    currentItem = item;
}

Item Player::getCurrentItem()const{
    return currentItem;
}

