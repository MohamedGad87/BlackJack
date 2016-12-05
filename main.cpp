#include <iostream>
#include <ctime>
#include <cstdlib>
#include "BlackJack.h"
using namespace std;

int main()
{
    //random seed
	srand((int) time(NULL));

	//create game
	BlackJack game;

	//play the game
	game.play();

    cin.ignore(2);
    return 0;
}
