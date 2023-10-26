#include <iostream> 


using namespace std;

// enum HeroType {WARRIOR, ELF, WIZARD};

// const double MAX_HEALTH = 100.0;

#include "Character.h"

Character::Character(HeroType type, const string& name, double health, double attStrength)
{
    this->type = type;
    this->name = name;
    this->health = health;
    attackStrength = attStrength;
}

HeroType Character:: getType() const
{
    return this->type;
}

const string& Character:: getName() const
{
    return this->name;
}

int Character:: getHealth() const
{
    return this->health;
}

void Character:: damage(double d)
{
    health -= d;
}

bool Character:: isAlive() const
{
    if(getHealth() > 0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
//void Character:: attack(character &att)


