//Final_Project (GoFishSource)
//April 20, 2015
//Elliot Benson
//Nic Wolfrum

#include "GoFish.h"
#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <vector>

GoFish::GoFish()
{

}

GoFish::~GoFish()
{

}


/*This function sets the suit and number of the card, and pushes it onto the deck vector.
This function is called 52 times in order to add all 52 cards of the deck read in from he deck.txt file.*/

/*
Function prototype:
void GoFish::addCard(std::string suit, int number)


Function description:
This method adds card structs to a vector data structure


Example:
GoFish *Obj = new GoFish();
Obj->addCard("Spades", 1)


Precondition: Uses a previouly initialized empty vector
Post condition: Add's cards to that vector to be used as the deck that will be shuffled, dealt, and drawn from
*/

void GoFish::addCard(std::string suit, int number)
{
	card* temp = new card;
	temp->suit = suit;
	temp->number = number;
	deck.push_back(temp);
}


/*This function shuffles the deck of cards using a built in random shuffle function for vectors.
This ensures that the game will be different every time it is played. It will only be called once.*/

/*
Function prototype:
void GoFish::shuffleDeck()


Function description:
This method shuffles the locations of the elements of the vector


Example:
GoFish *Obj = new GoFish();
Obj->shuffleDeck();


Precondition: Uses a built in random_shuffle
Post condition: Cards in vector end up in a different order
*/




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

/*
Function prototype:
void GoFish::dealCards()


Function description:
This method alternates locations of vector dealing 7 into each player's linked list


Example:
GoFish *Obj = new GoFish();
Obj->dealCards();


Precondition: Starts with a PlayerRoot and alternates integers adding every other card to each player's hand
Post condition: Cards in vector end up in a player's hand (linked list)
*/


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

			addCardHand("Player 1", tempx);


		}
		//every other card goes to Player 2's linked list of cards.
		else
		{
			card* tempx = deck.back();
			deck.pop_back();

			addCardHand("Player 2", tempx);
		}

	}
	cardsDealt = true;
}

/* This function prints out the cards the player currently holds. It can be called multiple times.
The function overall is pretty self explanatory.*/


/*
Function prototype:
void GoFish::revealCards()


Function description:
This method show's the user the cards in their hand


Example:
GoFish *Obj = new GoFish();
Obj->revealCards();


Precondition: n/a
Post condition: a loop that goes through linked list printing out the properties of each node (card)
*/



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


//void GoFish::searchCards(std::string Player, int val);

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

-If a number occurs 4 times in the new linked list, a "book" has been formed, and should be stored, and those values
removed from the linked list.

-Additionally, this function needs to be implemented in the reverse. After the Player's turn is complete, it is
the computers turn. We will need to write a function to find which value is repeated most in the computers linked list
(look through past rec. and assignments for algorithm / function? ).
Then, we search player 1's linked list for that value and do the same thing as before.
*/



/*
Function prototype:
void GoFish::searchCards(std::string Player, int val);

Function description:
This function is to search the opposing player's linked list for the desired value card and, if found, add the found
cards to the original players linked list. If no cards of the desired value are found in the opposing players linked list,
the player is required to draw from the pool of cards (automatically add deck.back() to Player 1's linked list)


Example:
GoFish *Obj = new GoFish();
Obj->searchCards("Player 1", 2);


Precondition: player's hands are untouched since shuffle deal and reveal
Post condition: iterate through linked list searching other player's cards to see if they have the card we ask for , and if it matches it removes from theirs and adds to ours or visa versa
*/

void GoFish::searchCards(std::string Player, int val){

	std::vector<card*> playerDeckTemp; //vector created to store cards
	bool cardFound1 = false; //creating a bool to keep track of whether or not the card has been found
	bool cardFound2 = false;

	if (Player == "Player 1"){ //check for which player is going-> same as argument passed
		card *head = Player2Root; //it was player 1 so we start searching through player2's cards
		while (head != NULL){ //use while loop to go through entire hand
			if (head->number == val){ //if the sorting is at a node with the card value that we want
				cardFound1 = true; //set card found equal to true
				removeCards("Player 2", val); //enter remove card function passing player 2 because we will remove the card from player2's hand
				std::cout << "Card/cards found." << std::endl;
				break; //break out of while loop 
			}
			head = head->next; //used to iterate through whole linked list
		}
		if (cardFound1 == false){ //card was not found in player 2's hand
			std::cout << "Player 2 does not have that card. Drawing card from deck" << std::endl;
			card* temp = deck.back();
			deck.pop_back();
			addCardHand("Player 1", temp); //adding card to player1's hand from the vector "deck" which is the remaining cards after the dealing
			std::cout << "You drew a " << temp->number << "!" << std::endl; //tell the user what card they drew
			if (isEmpty()){ //now need to check if the deck is empty because we removed a card from it
				playerMax("Player 1", Player1Root); //count's books in this case
				playerMax("Player 2", Player2Root);

				if (count1 > count2){ //compares book count to determine who won
					std::cout << "You won with " << count1 << " books." << std::endl;
					std::cout << "Player 2 had " << count2 << " books." << std::endl;
				}
				if (count2 > count1){
					std::cout << "Player 2 won with " << count2 << " books." << std::endl;
					std::cout << "You only had " << count1 << " books." << std::endl;
				}
				gameOver = true; //set gameOver to true
			}
		}
		playerMax("Player 1", Player1Root);

	}
	else{ //Player = Player 2 					SAME CODE AS PLAYER 1 BUT WITH THE PLAYER'S AND SOME FUNCTION ARGUMENTS SWITCHED
		card *current = Player1Root;
		while (current != NULL){
			if (current->number == val){
				cardFound2 = true;
				removeCards("Player 1", val);
				std::cout << "Player 2 took your " << val << "'s" << std::endl;
				break;
			}
			current = current->next;
		}
		if (cardFound2 == false){ //checking that the player2's card hasn't been found
			card* temp = deck.back();
			deck.pop_back();
			addCardHand("Player 2", temp);
			std::cout << "Player 1 does not have that card. Drawing card from deck" << std::endl;
			if (isEmpty()){
				playerMax("Player 1", Player1Root);
				playerMax("Player 2", Player2Root);

				if (count1 > count2){
					std::cout << "You won with " << count1 << " books." << std::endl;
					std::cout << "Player 2 had " << count2 << " books." << std::endl;
				}
				if (count2 > count1){
					std::cout << "Player 2 won with " << count2 << " books." << std::endl;
					std::cout << "You had " << count1 << " books." << std::endl;
				}
				gameOver = true;
			}
		}
		playerMax("Player 2", Player2Root);

	}


}



/*
Function prototype:
void GoFish::removeCards(std::string Player, int val)

Function description:
This method removes cards from the player passed in and gives them to the other player


Example:
GoFish* Obj = new GoFish();
Obj->removeCards("Player 1", 5)

Precondition: Each player has a given set of cards
Post condition: Player selected has essentially removed a card from their linked list and it is added to the other players'
*/



void GoFish::removeCards(std::string Player, int val){ //removes cards and gives them to the other player

	if (Player == "Player 1"){ //removing from player 1 and adding to player 2
		card *current = Player1Root;
		while (current != NULL){
			if (current->number == val){
				if (current->prev == NULL){ //head is the value to delete
					card* temp = new card;
					//set each individual item
					temp->number = current->number;
					temp->suit = current->suit;
					temp->next = NULL;
					temp->prev = NULL;
					addCardHand("Player 2", temp);
					Player1Root = current->next;
					current = current->next;
					current->next->prev = NULL;
				}
				else if (current->next == NULL){ //tail is value to delete
					card* temp = new card;
					//set each individual item
					temp->number = current->number;
					temp->suit = current->suit;
					temp->next = NULL;
					temp->prev = NULL;
					addCardHand("Player 2", temp);
					current->prev->next = NULL;
					current = NULL;

				}
				else{ //value to delete is in middle of list
					card* temp = new card;
					//set each individual item
					temp->number = current->number;
					temp->suit = current->suit;
					temp->next = NULL;
					temp->prev = NULL;
					addCardHand("Player 2", temp);

					current->prev->next = current->next;
					current->next->prev = current->prev;
					current = current->next;
				}
			}
			else
			{
				current = current->next;
			}
		}
	}
	else{ //Removing from player 2 and adding to player 1
		//card* temp = new card;
		card* current = Player2Root;
		while (current != NULL){
			if (current->number == val){

				if (current->prev == NULL){ //head is the value to delete

					card* temp = new card;
					//set each individual item
					temp->number = current->number;
					temp->suit = current->suit;
					temp->next = NULL;
					temp->prev = NULL;
					addCardHand("Player 1", temp);
					Player2Root = current->next;
					current = current->next;

					current->next->prev = NULL;
				}
				else if (current->next == NULL){ //tail is value to delete

					card* temp = new card;
					//set each individual item
					temp->number = current->number;
					temp->suit = current->suit;
					temp->next = NULL;
					temp->prev = NULL;
					addCardHand("Player 1", temp);
					current->prev->next = NULL;
					current = NULL;

				}
				else{ //value to delete is in middle of list

					card* temp = new card;
					//set each individual item
					temp->number = current->number;
					temp->suit = current->suit;
					temp->next = NULL;
					temp->prev = NULL;
					addCardHand("Player 1", temp);
					current->prev->next = current->next;
					current->next->prev = current->prev;
					//need to put add function here and at all other spots
					//delete current;
					current = current->next;
				}
			}
			else{
				current = current->next;
			}
		}


	}

}

/*
Function prototype:
void GoFish::addCardHand(std::string Player, card *tempx)

Function description:
This method is similar to the addCard above but is specified to add a card in the right order in a players hand. Right order is least to greatest


Example:
GoFish *Obj = new GoFish();
Obj->addCardHand("Player 1", tempx);


Precondition: pending location in the game, ususally used because of the remove function
Post condition: assures adding to correct player and starts at root and adds card at correct location in the linked list
*/

void GoFish::addCardHand(std::string Player, card *tempx){
	if (Player == "Player 1"){
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
	else if (Player == "Player 2"){
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


/*
Function prototype:
void GoFish::addCardHand(std::string Player, card *tempx)

Function description:
This method is inefficient for sure. However this goes through a players list of cards (hand) and stores them to a temp vector to find the card that occurs the most
Also keeps a count so that we can count books and remove them if there is a book present


Example:
GoFish *Obj = new GoFish();
Obj->playerMax("Player 1", Player1Root);


Precondition: cards are in hand and none is touched b/c we create new structures here
Post condition: created vector and int variables to store counts of how many cards occur and print them out
*/


int GoFish::playerMax(std::string player, card *PlayerRoot){

	card *head = new card;


	if (player == "Player 1"){
		head = Player1Root;
	}
	if (player == "Player 2"){
		head = Player2Root;
	}

	int one = 0;
	int two = 0;
	int three = 0;
	int four = 0;
	int five = 0;
	int six = 0;
	int seven = 0;
	int eight = 0;
	int nine = 0;
	int ten = 0;
	int eleven = 0;
	int twelve = 0;
	int thirteen = 0;

	while (head->next != NULL){
		if (head->number == 1){
			one++;
		}
		if (head->number == 2){
			two++;
		}
		if (head->number == 3){
			three++;
		}
		if (head->number == 4){
			four++;
		}
		if (head->number == 5){
			five++;
		}
		if (head->number == 6){
			six++;
		}
		if (head->number == 7){
			seven++;
		}
		if (head->number == 8){
			eight++;
		}
		if (head->number == 9){
			nine++;
		}
		if (head->number == 10){
			ten++;
		}
		if (head->number == 11){
			eleven++;
		}
		if (head->number == 12){
			twelve++;
		}
		if (head->number == 13){
			thirteen++;
		}
		head = head->next;
	}

	std::vector<int> largest;
	largest.push_back(one);
	largest.push_back(two);
	largest.push_back(three);
	largest.push_back(four);
	largest.push_back(five);
	largest.push_back(six);
	largest.push_back(seven);
	largest.push_back(eight);
	largest.push_back(nine);
	largest.push_back(ten);
	largest.push_back(eleven);
	largest.push_back(twelve);
	largest.push_back(thirteen);

	int maxElement = *std::max_element(largest.begin(), largest.end());

	int cardName = 0;
	for (unsigned int i = 0; i < largest.size(); i++){
		if (largest[i] == maxElement){
			cardName = i + 1; //cardName will still come out as the number on the card
			//std::cout << "There are " << maxElement << " " << cardName << "'s" << std::endl;
			//maxElement is the number of times a card with ID cardName occurred
			//cardName is card ID
		}
	}

	if (maxElement == 4){
		removeBook(player, cardName);
		if (player == "Player 1"){
			count1++;
			std::cout << "Player 1 now has " << count1 << " books!" << std::endl;

		}
		if (player == "Player 2"){
			count2++;
			std::cout << "Player 2 now has " << count2 << " books!" << std::endl;

		}
	}

	return cardName;
}

/*
Function prototype:
void GoFish::getPlayerRoot(std::string Player)

Function description:
This is a getter function for the root of each player's linked list (hand of cards)

Example:
GoFish *Obj = new GoFish();
Obj->getPlayerRoot("Player 1");


Precondition: playerRoots are private in the class
Post condition: converts the private nodes to "root" which can then be used in public functions
*/


card *GoFish::getPlayerRoot(std::string player){
	card* root = new card;
	if (player == "Player 1"){
		root = Player1Root;
	}
	if (player == "Player 2"){
		root = Player2Root;
	}
	return root;
}

/*
Function prototype:
void GoFish::isEmpty()

Function description:
Checks if deck is empty and if it is, returns true so that we know when the game is over.


Example:
GoFish *Obj = new GoFish();
Obj->playerMax("Player 1", Player1Root);


Precondition: deck has an empty function
Post condition: check to see if the deck has 0 elements and if it does return true
*/


bool GoFish::isEmpty(){
	if (deck.empty()){
		std::cout << "Game over" << std::endl;
		return true;
	}
	return false;
}



/*
Function prototype:
void GoFish::removeBook(std::string Player, int val)

Function description:
This method is checks to see the count of cards and if there are any four cards of the same number (books) and removing them and adding to a book count


Example:
GoFish *Obj = new GoFish();
Obj->removeBook("Player 1", 1);


Precondition: count is set, and vector is full
Post condition: if we find four, we remove from players hand and add to count for # of books
*/


void GoFish::removeBook(std::string Player, int val)
{
	if (Player == "Player 1"){ //removing from player 1 and adding to player 2
		card *current = Player1Root;
		while (current != NULL){
			if (current->number == val){
				if (current->prev == NULL){ //head is the value to delete

					Player1Root = current->next;
					current = current->next;
					current->next->prev = NULL;
				}
				else if (current->next == NULL){ //tail is value to delete

					current->prev->next = NULL;
					current = NULL;

				}
				else{ //value to delete is in middle of list

					current->prev->next = current->next;
					current->next->prev = current->prev;
					current = current->next;
				}
			}
			else
			{
				current = current->next;
			}
		}
	}
	else{ //Removing from player 2 and adding to player 1
		//card* temp = new card;
		card* current = Player2Root;
		while (current != NULL){
			if (current->number == val){

				if (current->prev == NULL){ //head is the value to delete

					Player2Root = current->next;
					current = current->next;

					current->next->prev = NULL;
				}
				else if (current->next == NULL){ //tail is value to delete

					current->prev->next = NULL;
					current = NULL;

				}
				else{ //value to delete is in middle of list


					current->prev->next = current->next;
					current->next->prev = current->prev;
					//need to put add function here and at all other spots
					//delete current;
					current = current->next;
				}
			}
			else{
				current = current->next;
			}
		}


	}

}

