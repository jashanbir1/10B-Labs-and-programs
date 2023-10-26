#include <iostream> 

using namespace std;

#include "Character.h"
#include "Elf.h"


Elf:: Elf(string name, double health, double attStrgth, string family) 
: Character(ELF, name, health, attStrgth), famName(family){}
void Elf:: attack(Character& contestant)
{
    //double percHealth = (health / MAX_HEALTH);
    double newAttack = this->attackStrength * (health / MAX_HEALTH);
    if(contestant.getType() == ELF)
    {
        Elf &elph = dynamic_cast<Elf &>(contestant);
        if(elph.getFamName() == famName)
        {
            cout << "Elf " << name << " does not attack Elf " << elph.getName() << "." << endl;
            cout << "They are both members of the " << getFamName() << " family." << endl;
            return;

        }
    }
    cout << "Elf " << name << " shoots an arrow at " << contestant.getName() << " --- TWANG!!" << endl;
    // double percHealth = 1.0 * (health / MAX_HEALTH);
    // attackStrength *= percHealth * 1.0;
    cout << contestant.getName() << " takes " << newAttack<< " damage." << endl;
    contestant.damage(newAttack);
}

string Elf:: getFamName() const
{
    return famName;
}