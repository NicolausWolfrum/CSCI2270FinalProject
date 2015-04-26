//Final_Project
//April 20, 2015
//Elliot Benson
//Nic Wolfrum

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include "GoFish.h"
#include <time.h>


//Function Prototypes
void printMenu();
void inputDeck();
GoFish* Obj = new GoFish();


int main(){
	inputDeck();	//input deck from file
	printMenu();	//print out menu
	std::string option, temp, search;
	while (option != "5"){
		std::cin >> option;
		if (option == "1"){
			if (Obj->cardsShuffled == false) //Have the Cards been shuffled already?
			{
				Obj->shuffleDeck();
				std::cout << "Cards shuffled." << std::endl;
			}
			else
			{
				std::cout << "You already shuffled the cards." << std::endl;
			}
			printMenu();
		}
		if (option == "2"){
			if (Obj->cardsShuffled == false) //Have the cards been shuffled?
			{
				std::cout << "Please shuffle the cards before dealing." << std::endl;
			}
			else if (Obj->cardsDealt == true)	//Were the cards already dealt?
			{
				std::cout << "You already dealt the cards." << std::endl;
			}
			else
			{
				Obj->dealCards();
				std::cout << "Cards dealt." << std::endl;
			}
			printMenu();
		}
		if (option == "3"){
			if (Obj->cardsDealt != true) // have the cards been dealt?
			{
				std::cout << "Please deal the cards first." << std::endl;
			}
			else
			{
				Obj->revealCards();
			}
			printMenu();
		}
		if (option == "4"){
			if (Obj->cardsDealt != true)	//Have the cards even been dealt?
			{
				std::cout << "You must deal the cards first." << std::endl;
			}
			else if (Obj->cardsRevealed != true) //Did you even look at your cards bro?
			{
				std::cout << "You should look at your cards first." << std::endl;
			}
			else
			{
				std::cout << "Enter 1 for Ace, 2 for 2, 3 for 3,  ... 11 for Jack, 12 for Queen, and 13 for King" << std::endl;
				std::cout << "What are you fishing for? " << std::endl;
				getline(std::cin, temp);
				getline(std::cin, search);
				Obj->searchCards("Player 1", atoi(search.c_str()));
				/*
				card *Player2Root = Obj->getPlayerRoot("Player 2");
				int newVal = Obj->player2Max(Player2Root);
				std::cout << "Player 2 going" << std::endl;
				//add delay of a few seconds in here
				Obj->searchCards("Player 2", newVal);
				*/
			}
			printMenu();
		}
	}

	std::cout << "Goodbye!" << std::endl;

	return 0;
}

void printMenu()
{
	std::cout << "======Main Menu======" << std::endl;
	std::cout << "1. Shuffle Cards" << std::endl;
	std::cout << "2. Deal Cards" << std::endl;
	std::cout << "3. Reveal Cards" << std::endl;
	std::cout << "4. Go Fishing" << std::endl;
	std::cout << "5. Quit" << std::endl;
}
void inputDeck()
{
	std::ifstream myFile("Deck.txt");
	std::string line, word, suit;
	int number = 0;
	std::string split = ",";
	if (myFile.is_open())
	{
		int j = 0;
		while (getline(myFile, line))
		{
			std::stringstream stream(line);
			int i = 1;
			while (getline(stream, word, ','))
			{
				if (i == 1)
				{
					suit = word;
				}
				else
				{
					number = atoi(word.c_str());
					Obj->addCard(suit, number);
					//std::cout << "Suit: " << suit << " ID: " << id << std::endl;
				}
				i++;
			}
		}
	}
}
