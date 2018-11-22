#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include <string>

using namespace std;

class Character
{
public:
    Character();
    Character(string name,string desc,int health,int strength,double hitChance);
    virtual string getName()const;
    virtual string getDesc()const;
    virtual int getStrength()const;
    virtual double getHitChance() const;
    virtual int getHealth() const;
    virtual void setHealth(int newHealth);
    virtual ~Character();

protected:
    string name;
    string desc;
    int health;
    int strength;
    double hitChance;
};

#endif // CHARACTER_H
