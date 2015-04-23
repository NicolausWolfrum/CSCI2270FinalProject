//Final_Project (GoFishSource)
//April 20, 2015
//Elliot Benson
//Nic Wolfrum

#include "GoFish.h"
#include <iostream>
#include <string>
#include <ctime>
#include<algorithm>

GoFish::GoFish()
{

}

GoFish::~GoFish()
{
}


/*This function sets the suit and number of the card, and pushes it onto the deck vector.
This function is called 52 times in order to add all 52 cards of the deck read in fromt he deck.txt file.*/
void GoFish::addCard(std::string suit, int number)
{
	card* temp = new card;
	temp->suit = suit;
	temp->number = number;
	deck.push_back(temp);
}


/*This function shuffles the deck of cards using a built in random shuffle function for vectors.
This ensures that the game will be different every time it is played. It will only be called once.*/
void GoFish::shuffleDeck()
{
	//random generator
	std::srand(unsigned(std::time(0)));
	std::random_shuffle(deck.begin(), deck.end());
	cardsShuffled = true;
	/*Uncomment to test that cards are being shuffled
	for (int i = 0; i < deck.size(); i++)
	{
	std::cout << "Suit: " << deck[i]->suit << ", Number: " << deck[i]->number << std::endl;
	}*/

}


/* This function builds two linked lists of cards, one for the player, one for the computers player.
The linked lists are built in numerical order in order to make searching easier down the road.
This function will only be called once.*/
void GoFish::dealCards()
{
	for (int i = 0; i < 14; i++)
	{
		//first card dealt is Player1Root (first card in Player 1's Linked List). 
		if (i == 0)
		{
			Player1Root = deck.back();
			deck.pop_back();	//removes card from deck vector
		}
		//second card dealt is Player2Root (First card in Player 2's Linked list).
		else if (i == 1)
		{
			Player2Root = deck.back();
			deck.pop_back();
		}
		//every other card goes to Player1's linked list of cards
		else if (i % 2 == 0)
		{
			card* tempx = deck.back();
			deck.pop_back();

			if (Player1Root->number >= tempx->number)
				//if card is beginning of list
			{
				tempx->next = Player1Root;
				Player1Root->prev = tempx;
				Player1Root = tempx;
			}
			else
			{
				card *current = Player1Root;
				//search for position of new node using a temp current node
				while (current->next != NULL && current->next->number < tempx->number)
				{
					current = current->next;
				}
				//new node is between current and current->next
				tempx->prev = current;
				tempx->next = current->next;
				//if the new node is at the end, can't update current->next->prev because it is null
				if (current->next != NULL)
				{
					current->next->prev = tempx;
				}
				//next of current points to new node
				current->next = tempx;
			}


		}
		//every other card goes to Player 2's linked list of cards.
		else
		{
			card* tempx = deck.back();
			deck.pop_back();

			if (Player2Root->number >= tempx->number)
				//if card is beginning of list
			{
				tempx->next = Player2Root;
				Player2Root->prev = tempx;
				Player2Root = tempx;
			}
			else
			{
				card *current = Player2Root;
				//search for position of new node using a temp current node
				while (current->next != NULL && current->next->number < tempx->number)
				{
					current = current->next;
				}
				//new node is between current and current->next
				tempx->prev = current;
				tempx->next = current->next;
				//if the new node is at the end, can't update current->next->prev because it is null
				if (current->next != NULL)
				{
					current->next->prev = tempx;
				}
				//next of current points to new node
				current->next = tempx;
			}
		}

	}
	cardsDealt = true;
}

/* This function prints out the cards the player currently holds. It can be called multiple times.
The function overall is pretty self explanatory.*/
void GoFish::revealCards()
{
	card* temp = Player1Root; //only want to print out Player 1's cards 
	std::cout << "Your Cards: " << std::endl;
	while (temp != NULL)
	{
		if (temp->number == 1)
		{
			std::cout << "Ace of " << temp->suit << std::endl;
		}
		else if (temp->number == 11)
		{
			std::cout << "Jack of " << temp->suit << std::endl;
		}
		else if (temp->number == 12)
		{
			std::cout << "Queen of " << temp->suit << std::endl;
		}
		else if (temp->number == 13)
		{
			std::cout << "King of " << temp->suit << std::endl;
		}
		else
		{
			std::cout << temp->number << " of " << temp->suit << std::endl;
		}

		temp = temp->next;
	}
	cardsRevealed = true;
}
/*This function is to search the opposing player's linked list for the desired value card and, if found, add the found
cards to the original players linked list. If no cards of the desired value are found in the opposing players linked list,
the player is required to draw from the pool of cards (automatically add deck.back() to Player 1's linked list).
What still needs implemented:

-before a card is deleted, it should be stored in a temporary location (i would suggest a queue or a vector),
which after the search is complete, those cards will be added to player 1's linked list.

-It would most likely be easiest to create a whole "addCard" function, that could be called to add cards to
each players linked list. It could be used in this function as well as in the dealCards function. It would be structured
as void addCard(std::string player, card* temp). Player is the players linked list it is meant to go into,
temp is the card you're adding.

-If a number occrus 4 times in the new linked list, a "book" has been formed, and should be stored, and those values
removed from the linked list.

-Additionally, this function needs to be implemented in the reverse. After the Player's turn is complete, it is
the computuers turn. We will need to write a function to find which value is repeated most in the computers linked list
(look through past rec. and assignemnts for algorithm / function? ).
Then, we search player 1's linked list for that value and do the same thing as before.
*/
void GoFish::searchCards(std::string Player, int val)
{
	int count = 0;
	if (Player == "Player 1")
	{
		card* current = Player2Root;
		while (current->number == val)
		{
			card* temp = current;
			current = current->next;
			Player2Root = current;
			//Before deleting, store the card to be added to player 1's list.
			delete temp;
			count++;
		}
		while (current->next != NULL)
		{
			if (current->next->number == val)
			{
				card* temp = current->next;
				current->next = current->next->next;
				//Before deleting, store card to be added to player 1's list
				delete temp;
				count++;
			}
			else
			{
				current = current->next;
			}
		}
	}

	std::cout << "Player 2 had " << count << " " << val << "'s" << std::endl;


}
