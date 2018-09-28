#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item{
private:
    std::string name;
    bool checkWeapon;

public:
    ~Item();
    Item(std::string newName,bool checkWeapon);
    Item();
    std::string getName() const;
    std::string getDescription();
    bool getCheckWeapon() const;
    bool operator==(const std::string& itemName);
};

#endif // ITEM_H
