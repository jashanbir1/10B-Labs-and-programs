#include <iostream> 

using namespace std;

#include "Character.h"
#include "Warrior.h"

Warrior:: Warrior (string name, double health, double attackStrength, string allgnce) :
Character(WARRIOR, name, health, attackStrength), allegiance(allgnce) 
{}

void Warrior:: attack(Character& contestant)
{

    //double percHealth = health / MAX_HEALTH;
    double newAttack =  this->attackStrength * (health / MAX_HEALTH);
    if(contestant.getType() == WARRIOR)
    {
        Warrior &opp = dynamic_cast<Warrior &>(contestant);
        if(opp.getAllegiance() == allegiance)
        {
            cout << "Warrior " << name << " does not attack Warrior " << opp.getName() << "." << endl;
            cout << "They share an allegiance with " << getAllegiance() << "."<< endl;
            return;
        }
    }
    
    cout << "Warrior " << name << " attacks " <<  contestant.getName() << " --- SLASH!!" << endl;
    cout << contestant.getName() << " takes " << newAttack << " damage." << endl;
    contestant.damage(newAttack);
}

string Warrior:: getAllegiance() const
{
    return this->allegiance;
}
