#include <ostream>
#include <iostream>
#include <cmath>
#include "Distance.h"
using namespace std;




Distance::Distance()
{
     this->_feet = 0;
     this->_inches = 0.0;
}

Distance::Distance(unsigned ft, double in)
{
     // if((in >= 12) || (in < 0.0))
     // {
     //      init();
          this->_feet = ft;
          this->_inches = in;
          init();
     // }
     // else
     // {
          // this->_feet = ft;
          // this->_inches = in;
     //}
}

Distance::Distance(double in)
{
     this->_feet = 0;
     this->_inches = in;
     init();
}

unsigned Distance:: getFeet() const
{
     return this->_feet;
}

double Distance:: getInches() const
{
     return this->_inches;
}

double Distance:: distanceInInches() const
{
     unsigned ftToIn;

     ftToIn = this->_feet * 12;

     return ftToIn + this->_inches;


}

double Distance:: distanceInFeet() const
{
     double inToFt;

     inToFt = this->_inches / 12.0;

     return this->_feet + inToFt;
}

double Distance:: distanceInMeters() const
{
     double inToMtr;
     double ftToMtr;

     inToMtr = this->_inches * .0254;
     ftToMtr = this->_feet * .3048;

     return inToMtr + ftToMtr;

}


Distance Distance:: operator+(const Distance &rhs) const
{
     double sum;

     sum = distanceInInches() + rhs.distanceInInches();
     return sum;
}

Distance Distance:: operator-(const Distance &rhs) const
{
     double subtract;

     subtract = distanceInInches() - rhs.distanceInInches();
     return subtract;
}
ostream& operator<<(ostream &out, const Distance &rhs)
{
     return out << rhs._feet << "'" << " " << rhs._inches << "\"";
}

void Distance:: init()
{

     if (this->_inches < 0.0)
     {
          this->_inches *= -1;
     }
     while (this->_inches >= 12.0 )
     {
          this->_inches = this->_inches - 12;
          this->_feet += 1;
     }
}

//ASK QUESTION ON WHAT IS DIFFERENCE BETWEEN EXPLICIT AND IMPLICIT 
//ASK QUESTION ON OSTREAM& OPERATOR 


