#include "LinkedList.h"

LinkedList::LinkedList(int s)			//Construtor with default parameter 52
{
  size = 0;
  cards = new Card[s];
}

Card LinkedList::getFirst()				//get first card in the list
{
	Card card;
    if(!isEmpty())
		return cards[0];
	return card;
}

void LinkedList::removeFirst()				//remove first card from the list
{
   if(!isEmpty())
   {
      for(int i=0; i<size-1; i++)
	  {
	     cards[i] = cards[i+1];
	  }
	  size--;
   }
}

void LinkedList::insert(Card card)				//insert card at the end of list
{
  if(!isFull())
  {
	  cards[size++] = card;
  }
}

bool LinkedList::isEmpty()					//test if list is empty
{
  return size == 0;
}

bool LinkedList::isFull()					//test if list is full
{
  return size == MAX;
}

void LinkedList::shuffle()					//shuffle the list of cards
{
   //suffle the cards with random indexex
	int i, j, k;

	for(i=0; i<size; i++)
	{
	   j = rand() % size;
	   k = rand() % size;
	   Card tmp = cards[j];
	   cards[j] = cards[k];
	   cards[k] = tmp;
	}
}

int LinkedList::getValue()					//get value of cards in list, useful for player's hand
{
   int total = 0;
   for(int i=0; i<size; i++)
   {
	   total += cards[i].getValue();
   }
   return total;
}

void LinkedList::display()					//display cards in list, useful for player's hand
{

  cout << "\t\t";
  for(int i=0; i<size; i++)
  {
	  cards[i].display();
  }
  cout << right << setw(8) << "Value=" << getValue() << endl;
}
