#include "BlackJack.h"

void BlackJack::play()							//play the game
{
    int round = 0;
    int ties = 0;
    int dealerWins = 0;
    int playerWins = 0;
    char option;
    char keepPlaying = 'Y';

    //Welcome message
    welcome();

    //shuffle the deck
    deck.shuffle();

    do
    {
        round++;

        //if deck is low clear and reset
        if(deck.isLow())
        {
            deck.clear();
            deck.init();
            deck.shuffle();
        }


        //clear hands
        player.clear();
        dealer.clear();

        cout << "Round No. " << round << endl;
        cout << "====================" << endl << endl;
        //deal initial Cards
        cout << "Dealing Initial Cards" << endl << endl;

        dealInitial(player);
        dealInitial(dealer);

        //display Hands
        displayHands();

        //check if someone has a Black Jack
        if(isBlackJack(player))
        {
            cout << "Player got a Black Jack." << endl;
            cout << "Player Won the Round" << endl;
            playerWins++;
        }
        else if(isBlackJack(dealer))
        {
            cout << "Dealer got a Black Jack." << endl;
            cout << "Dealer Won the Round" << endl;
            dealerWins++;
        }
        else
        {
            //Let the Player Hit or Stand
            do
            {
                option = getInput();

                //if hit
                if(option == 'H')
                {
                    //add a Card to Player
                    cout << "Player Hits: " << endl;
                    Card card = deck.distribute();
                    card.display();
                    player.insert(card);
                    cout << endl;
                    displayHands();
                    cout << endl;
                    //check if player is busted or black jack
                    if(isBusted(player))
                    {
                        cout << "Player is Busted!" << endl;
                        cout << "Dealer Won the round" << endl;
                        dealerWins++;
                        break;
                    }
                    else if(isBlackJack(player))
                    {
                        cout << "Player got a Black Jack." << endl;
                        cout << "Player Won the Round" << endl;
                        playerWins++;
                        break;
                    }
                }
            }while(option == 'H');

            //deal for dealer
            if(!isBusted(player) && !isBlackJack(player))
            {
                dealerHits(dealer);

                if(isBusted(dealer))
                {
                    cout << "Dealer is Busted!" << endl;
                    cout << "Player Won the round" << endl;
                    playerWins++;
                }
                else if(isBlackJack(dealer))
                {
                    cout << "Dealer got a Black Jack." << endl;
                    cout << "Dealer Won the Round" << endl;
                    dealerWins++;
                }

                //check Winner
                int rs = checkWinner();

                if(rs == 1)
                    playerWins++;
                else if(rs == 2)
                    dealerWins++;
                else
                    ties++;
            }
        }

        //want to play next round
        cout << endl;
        cout << "Would you like to play again? (Y/N): ";
        cin >> keepPlaying;
        keepPlaying = toupper(keepPlaying);
        cout << endl << endl;
    }while(keepPlaying == 'Y');

}

char BlackJack::getInput()						//get input for Hit or Stand
{
    char option = ' ';
	do
	{

        cout << "\nPlayer Select Option (H/S): " << endl;
        cout << "  [H]it" << endl;
        cout << "  [S]tand" << endl;
        cout << " > ";
        cin >> option;
        option = toupper(option);
	}while(option != 'H' && option != 'S');
return option;
}

void BlackJack::welcome()
{
    cout << endl;
    cout << "////////////////////////////////////////////////////////////" << endl;
	cout << "/////////  Welcome to Black Jack Game //////////////////////" << endl;
	cout << "////////////////////////////////////////////////////////////" << endl<< endl;
}

bool BlackJack::isBusted(Hand hand)	//is busted
{
    if(hand.getValue() > 21)
        return true;
    return false;
}
bool BlackJack::isBlackJack(Hand hand)//is black jack
{
    if(hand.getValue() == 21)
        return true;
    return false;
}

int BlackJack::checkWinner() //check winner of game
{
    if(isBusted(dealer) || isBlackJack(player))
    {
        if(isBlackJack(player))
            cout << "Player got a Black Jack." << endl;
        if(isBusted(dealer))
            cout << "Dealer is Busted." << endl;
        cout << "Player Won the Round" << endl;
        return 1;
    }
    else if(isBusted(player) || isBlackJack(dealer))
    {
        if(isBlackJack(dealer))
            cout << "Dealer got a Black Jack." << endl;
        if(isBusted(player))
            cout << "Dealer is Busted." << endl;
        cout << "Player is Busted." << endl;
        cout << "Dealer Won the Game" << endl;
        return 2;
    }
    else if(player.getValue() > dealer.getValue())
    {
        cout << "Dealer Value: " << dealer.getValue() << endl;
        cout << "Player Value: " << player.getValue() << endl;
        cout << "Player Won the Game" << endl;
        return 1;
    }
    else if(player.getValue() < dealer.getValue())
    {
        cout << "Dealer Value: " << dealer.getValue() << endl;
        cout << "Player Value: " << player.getValue() << endl;
        cout << "Dealer Won the Game" << endl;
        return 2;
    }
    else
    {
        cout << "Dealer Value: " << dealer.getValue() << endl;
        cout << "Player Value: " << player.getValue() << endl;
        cout << "Its a Tie." << endl;
        return 0;
    }
}
void BlackJack::dealInitial(Hand &hand)			//draw initial cards
{
    hand.insert(deck.distribute());
    hand.insert(deck.distribute());
}

void BlackJack::dealerHits(Hand &hand)
{
    while(hand.getValue() <= 17)
    {
        Card card = deck.distribute();
        cout << endl;
        cout << "Dealer Hits and Got: " << endl;
        card.display();
        cout << endl;
        hand.insert(card);

        displayHands();
    }
}

void BlackJack::displayHands() //display hands
{
    cout << "Player Hand: " << endl;
    player.display();
    cout << endl;
    cout << "Dealer Hand: " << endl;
    dealer.display();
    cout << endl;
}
