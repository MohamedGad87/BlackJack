#ifndef HAND_H
#define HAND_H
#include <iostream>
#include "LinkedList.h"
#include "Card.h"

using namespace std;

class Hand
{
public:
  Hand(); //default constructor
  void insert(Card card); //insert a card
  int getValue(); //get value of hand (all cards in player's hand
  void display(); //display player's hand
  void clear()
  {
      lst->clear();
  }
private:
  LinkedList * lst;
};
#endif
