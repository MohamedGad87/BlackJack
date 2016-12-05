#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Card
{
public:
	Card();							//Default Constructor
	Card(string, string);			//parameteric constructor
	string getFace();				//get face of card
	string getSuit();				//get suit of card
	int getValue();				//get card's actual value
	void setFace(string);			//set face of card
	void setSuit(string);			//set suit of card
	void display();					//display card
private:
	string face;
	string suit;
};

#endif
