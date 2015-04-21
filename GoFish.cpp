//Final_Project (GoFishSource)
//April 20, 2015
//Elliot Benson
//Nic Wolfrum

#include "GoFish.h"
#include <iostream>
#include <string>
#include<algorithm>

GoFish::GoFish()
{

}

GoFish::~GoFish()
{
}
//This function sets the suit and number of the card, and pushes it onto the deck vector.
void GoFish::addCard(std::string suit, int number)
{
	card* temp = new card;
	temp->suit = suit;
	temp->number = number;
	deck.push_back(temp);
}
//This function shuffles the deck of cards using a built in random shuffle function for vectors.
void GoFish::shuffleDeck()
{
	std::random_shuffle(deck.begin(), deck.end());
	/* Uncomment to test that cards are being shuffled
	for (int i = 0; i < deck.size(); i++)
	{
	std::cout << "Suit: " << deck[i]->suit << ", Number: " << deck[i]->number << std::endl;
	}
	*/
}