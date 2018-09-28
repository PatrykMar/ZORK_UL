#include "item.h"
using namespace std;

bool Item::operator==(const string& itemName){
    bool returnBool;
    if(this->getName().compare(itemName)==0){
        returnBool = 1;
    }
    else{
        returnBool =0;
    }
    return returnBool;
}
Item::Item() {}

Item::~Item() {}

Item::Item(string newName,bool newCheckWeapon){
    name = newName;
    checkWeapon = newCheckWeapon;
}

bool Item::getCheckWeapon()const{
    return checkWeapon;
}

string Item::getName()const{
    return name;
}

string Item::getDescription()
{
    return " item(s), " + name + ".\n";
}
