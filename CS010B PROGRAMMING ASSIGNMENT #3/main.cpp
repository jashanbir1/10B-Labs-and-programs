#include <iostream>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

#include "Deck.h"
#include "Card.h"

// Returns true if vector of Cards passed in contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &hand)
{
    for(unsigned int i = 0; i < hand.size(); ++i)
    {
        for(unsigned int j = i + 1; j < hand.size(); ++j)
        {
            if (hand.at(i).getRank() == hand.at(j).getRank())
            {
                return true;
            }
            // else 
            // {
            //     return false;
            // }
        }
    }
    return false;
}

// Sends to output stream a hand of Cards on a single line, 
// each Card separated by a comma.
// If the vector is empty, do not output anything.
// Example (vector size of 3): Ace of Spades, Two of Hearts, King of Clubs 
ostream & operator<<(ostream &oput, const vector<Card> & hand)
{
   
    
    for(unsigned int i = 0; i < hand.size(); ++i)
    {
        oput << hand.at(i)<< ",";
    }
    oput << hand.at(hand.size() -1);
    return oput;
    
}

int main() {
    srand(2222);
    ofstream o;
    string fileName;
    string choice;
    int nCards=0;
    int nDeals=0;
    int numPairs = 0;
    double chncOfPair;
    Deck d;
    vector<Card> hand;

    cout << "Do you want to output all hands to a file? (Yes/No)" << endl;
    cin >> choice;

    if(choice == "Yes")
    {
        cout << "Enter name of output file: " << endl;
        cin >> fileName;
        o.open(fileName);

        if(!o.is_open())
        {
            cout << "Error opening " << fileName << endl;
            exit(1);
        }
    }
    

    cout << "Enter number of cards per hand:";
    cin >> nCards;
    cout << endl;

    cout << "Enter number of deals (simulations): ";
    cin >> nDeals;
    cout << endl;
    
    for( int i = 0; i < nDeals; ++i)
    {
        d.shuffleDeck();
        hand.clear();
        for( int k = 0; k < nCards; ++k)
        {
            hand.push_back(d.dealCard());

        }
        if (hasPair(hand))
        {
            ++numPairs;
            o << "Found Pair!! ";
        }
        else 
        {
            o << "             ";
        }
        for (unsigned int i = 0; i < hand.size() - 1; ++i)
        {
            
            o << hand.at(i) << ", ";
            
        }
        o << hand.back();
        o << endl;
    }

    chncOfPair = 100.0 * (static_cast<double>(numPairs) / nDeals);

    cout << "Chances of receiving a pair in a hand of " << nCards << " cards is: " << chncOfPair << "%" << endl;

    o.close();

    return 0;
}