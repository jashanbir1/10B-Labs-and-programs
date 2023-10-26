#include <iostream>

using namespace std;

#include "Character.h"

class Warrior: public Character
{
    private: 
    string allegiance;

    public:
    Warrior(string,double, double, string);
    void attack(Character& ) override;
    string getAllegiance() const;
};