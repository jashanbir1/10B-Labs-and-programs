#include <iostream>
using namespace std;
#include "Card.h"

Card:: Card()
{
   this->suit = 'c';
   this->rank = 2;
   //ACCEPTS LOWER AND UPPERCASE LETTERS
}


Card:: Card (char a, int b)
{
   this->suit = a;
   this->rank = b;

   if (this->rank > 13 || this->rank < 1)
   {
      this->rank = 2;
   }
   else
   {
      this->rank = b;
   }
   if( this->suit == 'C' || this->suit == 'c')
   {
      this->suit = 'c';
   }
   else if(this->suit =='D' || this->suit == 'd')
   {
      this->suit = 'd';
   }
   else if(this->suit =='H' || this->suit == 'h')
   {
      this->suit = 'h';
   }
   else if(this->suit == 'S' || this->suit =='s')
   {
      this->suit = 's';
   }
   else
   {
      this->suit = 'c';
   }
   
   


}
char Card::getSuit() const
{
   return this->suit;
}

int Card:: getRank() const
{
   return this->rank;
}

ostream & operator<<(ostream & oput, const Card & crd)
{
   if(crd.rank == 1)
   {
      oput << "Ace of ";
   }
   else if (crd.rank == 11)
   {
      oput << "Jack of ";
   }
   else if (crd.rank == 12)
   {
      oput << "Queen of ";
   }
   else if (crd.rank == 13)
   {
      oput << "King of ";
   }
   else if (crd.rank >= 2 && crd.rank <= 10)
   {
      oput << crd.rank << " of ";
   }
   if(crd.suit == 'c')
   {
      oput << "Clubs";
   }
   
   else if (crd.suit == 'd')
   {
      oput << "Diamonds";
   }

   else if (crd.suit == 's')
   {
      oput << "Spades";
   }
   else if (crd.suit == 'h')
   {
      oput << "Hearts";
   }
   
   return oput;

}


//#endif