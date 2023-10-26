#include <iostream> 

using namespace std;

#include "Character.h"


class Elf: public Character
{
    private:
    string famName;

    public:
    Elf(string, double, double, string);
    void attack(Character& );
    string getFamName() const;
    
};