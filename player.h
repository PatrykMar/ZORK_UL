#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "item.h"
#include "character.h"

class Player : public Character
{
public:
    void addItem(Item *item);
    Player(std::string name,int health,double hitChance);
    Player();
    std::vector <Item*> getItemsInChar()const;
    void setCurrentItem(Item item);
    Item getCurrentItem()const;
    ~Player();

private:
    std::vector <Item*> itemsInChar;
    Item currentItem;
};

#endif // PLAYER_H
