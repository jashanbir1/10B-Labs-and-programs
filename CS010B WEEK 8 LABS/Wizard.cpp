#include <iostream> 

using namespace std;

#include "Wizard.h"
#include "Character.h"

Wizard:: Wizard(string name, double health, double attackStrength,int rnk):
Character(WIZARD, name, health, attackStrength), rank(rnk)
{}

void Wizard:: attack(Character& contestant)
{
   
    cout << "Wizard " << name << " attacks " << contestant.getName() << " --- POOF!!" << endl;
    double wizAttack;
    wizAttack = attackStrength;
    if(contestant.getType() == WIZARD)
    {
        
        Wizard& wzrd = dynamic_cast<Wizard &>(contestant);
        wizAttack = attackStrength * (rank * 1.0 / wzrd.getRank());
        cout << contestant.getName() << " takes " << wizAttack << " damage." << endl;
    }
    else
    {
        cout << contestant.getName() << " takes " << wizAttack << " damage." << endl;

    }
    contestant.damage(wizAttack);
   
}

int Wizard:: getRank() const
{
    return rank;
}