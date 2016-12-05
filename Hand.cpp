#include "Hand.h"

Hand::Hand()
{
	lst = new LinkedList(10);
}

void Hand::insert(Card card) //insert a card
{
  lst->insert(card);
}

int Hand::getValue() //get value of hand (all cards in player's hand
{
  return lst->getValue();
}

void Hand::display() //display player's hand
{
  lst->display();
}
