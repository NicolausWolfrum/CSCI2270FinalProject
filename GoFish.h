//Final_Project (GoFishHeader)
//April 20, 2015
//Elliot Benson
//Nic Wolfrum

#ifndef GOFISH_H
#define GOFISH_H

#include <iostream>
#include <string>
#include <vector>


//creating a struct "card" which we will use for a linked list of cards, contains card number and suit 
struct card{
	int number;
	std::string suit;
	card* next = NULL;
	card* prev = NULL;

};


//GoFish class with main functions as well as setting the roots for each players linked list in private
class GoFish
{

public:
	GoFish();
	virtual ~GoFish();
	void addCard(std::string, int);
	void shuffleDeck();
	void dealCards();
	void revealCards();
	void searchCards(std::string Player, int val);
	void removeCards(std::string Player, int val);
	void addCardHand(std::string Player, card *tempx);
	void removeBook(std::string Player, int val);
	int playerMax(std::string player, card *player2Root);
	card *getPlayerRoot(std::string player);
	bool isEmpty();
	bool cardsShuffled = false;
	bool cardsDealt = false;
	bool cardsRevealed = false;
	bool gameOver = false;
	int count1 = 0;
	int count2 = 0;


private:
	std::vector <card*> deck;
	card* Player1Root = NULL;
	card* Player2Root = NULL;
};

#endif // GOFISH_H

