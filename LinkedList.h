#ifndef LINKEDLIST_H
#define LINKEDLIST_H
/****************************************
 * class to implement array based list
 * of cards having support for removing
 * adding and suffling the list of cards
 ***************************************/
#include <iostream>

#include <string>
#include <cstdlib>
#include "Card.h"

using namespace std;

#define MAX 52

class LinkedList
{
public:
	LinkedList(int s = 52);			//Construtor with default parameter 52
	Card getFirst();				//get first card in the list
	void removeFirst();				//remove first card from the list
	void insert(Card);				//insert card at the end of list
	bool isEmpty();					//test if list is empty
	bool isFull();					//test if list is full
	void shuffle();					//shuffle the list of cards
	int getValue();					//get value of cards in list, useful for player's hand
	void display();					//display cards in list, useful for player's hand
    bool isLow()
    {
        return size < 4;
    }
    void clear()
    {
        size = 0;
    }
private:
	Card * cards;
    int size;
};
#endif
