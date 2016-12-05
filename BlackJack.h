#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

#include "Deck.h"
#include "Hand.h"
#include "Card.h"

using namespace std;

class BlackJack
{
public:
    void play();							//play the game
	char getInput();						//get input for Hit or Stand
	void welcome();							//welcome and rules
	bool isBusted(Hand hand);				//is busted
	bool isBlackJack(Hand hand);			//is black jack
	int checkWinner();						//check winner of game
	void dealInitial(Hand &hand);			//draw initial cards
	void dealerHits(Hand &hand);            //Dealer deals upto 17 points
	void displayHands();					//display hands
private:
	Hand player;
	Hand dealer;
	Deck deck;
};
#endif
