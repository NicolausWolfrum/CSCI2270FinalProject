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
	int count1 = 0;
	int count2 = 0;
	void searchCards(std::string Player, int val);
	void removeCards(std::string Player, int val);
	void addCardHand(std::string Player, card *tempx);
	int playerMax(std::string player, card *player2Root);
	card *getPlayerRoot(std::string player);
	bool isEmpty();


private:
	std::vector <card*> deck;
	card* Player1Root = NULL;
	card* Player2Root = NULL;
};

#endif // GOFISH_H

