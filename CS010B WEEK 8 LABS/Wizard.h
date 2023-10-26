#include <iostream>

using namespace std;

#include "Character.h"

class Wizard: public Character
{
    private:
    int rank;

    public:
    Wizard(string, double, double, int);
    void attack(Character&) override;
    int getRank() const;

};