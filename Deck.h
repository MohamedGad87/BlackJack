#ifndef DECK_H
#define DECK_H
#include <iostream>
#include "LinkedList.h"
#include "Card.h"

using namespace std;

class Deck
{
public:
	Deck(int s = 52);					//parameteric oncstructor to initialize deck
	void init();				//init function to create 52 cards of 4 suits, 13 cards each
	void shuffle();				//shuffle the deck
	Card distribute();			//distribute a card
	bool isEmpty();				//deck is empty
	bool isLow()
	{
	   return lst->isLow();
	}

	void clear()
    {
      lst->clear();
    }

private:
	LinkedList * lst;
};
#endif
