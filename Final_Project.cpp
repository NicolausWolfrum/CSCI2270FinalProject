//Final_Project
//April 20, 2015
//Elliot Benson
//Nic Wolfrum

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include "GoFish.h"


//Function Prototypes
void printMenu();
void inputDeck();
GoFish* Obj = new GoFish();


int main(){
	inputDeck();	//input deck from file
	printMenu();	//print out menu
	std::string option;
	while (option != "5"){
		std::cin >> option;
		if (option == "1"){
			Obj->shuffleDeck();
			printMenu();
		}
		if (option == "2"){

			printMenu();
		}
		if (option == "3"){

			printMenu();
		}
		if (option == "4"){
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