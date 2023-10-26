#include <iostream>
#include <algorithm>
using namespace std;

#include "Deck.h"
#include "Card.h"
Deck :: Deck()
{
   //vector<char> suits2(4);

   vector<char> suits2;

   suits2.push_back('s'); //0
   suits2.push_back('h'); //1
   suits2.push_back('d'); //2
   suits2.push_back('c'); //3
   
   for (unsigned int i = 0; i < suits2.size(); ++i)
   {
      for (unsigned int k = 13; k > 0; --k)
      {
         theDeck.push_back(Card(suits2.at(i),k));
      }

   }

}

Card Deck:: dealCard()
{
   Card var;
   var = theDeck.back();
   dealtCards.push_back(var);
   theDeck.pop_back();
   //dealtCards.push_back(var);
   return dealtCards.back();
}

void Deck:: shuffleDeck()
{
   for (unsigned int i = 0; i < dealtCards.size(); ++i)
   {
      theDeck.push_back(dealtCards.at(i));
   }
   dealtCards.clear();

   random_shuffle(theDeck.begin(), theDeck.end());
}

unsigned Deck:: deckSize() const
{
   return theDeck.size();
}
//#endif

