//Final_Project (GoFishHeader)
//April 20, 2015
//Elliot Benson
//Nic Wolfrum

#ifndef GOFISH_H
#define GOFISH_H

#include <iostream>
#include <string>
#include <vector>

struct card{
	int number;
	std::string suit;
	card* next = NULL;
	card* prev = NULL;

};

class GoFish
{

public:
	GoFish();
	virtual ~GoFish();
	void addCard(std::string, int);
	void shuffleDeck();
	void dealCards();
	void revealCards();
	bool cardsShuffled = false;
	bool cardsDealt = false;
	bool cardsRevealed = false;
	void searchCards(std::string, int);

private:
	std::vector <card*> deck;
	card* Player1Root;
	card* Player2Root;
};

#endif // GOFISH_H

