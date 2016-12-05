#include "Card.h"

Card::Card()							//Default Constructor
: face(""), suit("")
{}

Card::Card(string f, string s)			//parameteric constructor
: face(f), suit(s)
{}

string Card::getFace()				//get face of card
{
	return face;
}

string Card::getSuit()				//get suit of card
{
	return suit;
}

int Card::getValue()//get card's actual value
{
  if(face == "2")
	  return 2;
  else if(face == "3")
	  return 3;
  else if(face == "4")
	  return 4;
  else if(face == "5")
	  return 5;
  else if(face == "6")
	  return 6;
  else if(face == "7")
	  return 7;
  else if(face == "8")
	  return 8;
  else if(face == "9")
	  return 9;
  else if(face == "10" || face == "J" || face == "Q" || face == "K")
	  return 10;
  else if(face == "A")
	  return 11;
  else return 0;
}

void Card::setFace(string f)			//set face of card
{
   face = f;
}

void Card::setSuit(string s)			//set suit of card
{
	suit = s;
}

void Card::display()					//display card
{
  cout << right << setw(3) << face << left << setw(3) << suit;
}
