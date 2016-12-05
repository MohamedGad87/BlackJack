#include "Deck.h"

Deck::Deck(int s)					//parameteric oncstructor to initialize deck
{
  lst = new LinkedList(s); //list with 52 cards
  init();
}

void Deck::init()				//init function to create 52 cards of 4 suits, 13 cards each
{
	string suits [] = {"S", "H", "D", "C"};
	string faces [] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

	for(int i=0; i<4; i++)
	{
	  for(int j=0; j<13; j++)
	  {
	     Card card(faces[j], suits[i]);
		 lst->insert(card);
	  }
	}
}

void Deck::shuffle()				//shuffle the deck
{
  lst->shuffle();
}

Card Deck::distribute()			//distribute a card
{
  Card card = lst->getFirst();
  lst->removeFirst();
  return card;
}

bool Deck::isEmpty()				//deck is empty
{
   return lst->isEmpty();
}
