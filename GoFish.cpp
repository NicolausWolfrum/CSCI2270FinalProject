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
	}/*
	 temp = Player2Root; //only want to print out Player 1's cards
	 std::cout << "Computer's Cards: " << std::endl;
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
	 }*/
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

-If a number occurs 4 times in the new linked list, a "book" has been formed, and should be stored, and those values
removed from the linked list.

-Additionally, this function needs to be implemented in the reverse. After the Player's turn is complete, it is
the computers turn. We will need to write a function to find which value is repeated most in the computers linked list
(look through past rec. and assignments for algorithm / function? ).
Then, we search player 1's linked list for that value and do the same thing as before.
*/
void GoFish::searchCards(std::string Player, int val){

	std::vector<card*> playerDeckTemp; //vector created
	bool cardFound1 = false;
	bool cardFound2 = false;

	if (Player == "Player 1"){
		card *head = Player2Root;
		while (head != NULL){
			if (head->number == val){
				cardFound1 = true;
				removeCards("Player 2", val);
				std::cout << "Card/cards found." << std::endl;
				break;
			}
			head = head->next;
		}
		if (cardFound1 == false){
			std::cout << "Player 2 does not have that card. Drawing card from deck" << std::endl;
			card* temp = deck.back();
			deck.pop_back();
			addCardHand("Player 1", temp);
			std::cout << "You drew a " << temp->number << "!" << std::endl;
			if (isEmpty()){
				playerMax("Player 1", Player1Root);
				playerMax("Player 2", Player2Root);

				if (count1 > count2){
					std::cout << "Player 1 won with " << count1 << " books." << std::endl;
				}
				if (count2 > count1){
					std::cout << "Player 2 won with " << count2 << " books." << std::endl;
				}
				gameOver = true;
			}
		}
		playerMax("Player 1", Player1Root);

	}
	else{ //Player = Player 2
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
		if (cardFound2 == false){
			card* temp = deck.back();
			deck.pop_back();
			addCardHand("Player 2", temp);
			std::cout << "Player 1 does not have that card. Drawing card from deck" << std::endl;
			if (isEmpty()){
				playerMax("Player 1", Player1Root);
				playerMax("Player 2", Player2Root);

				if (count1 > count2){
					std::cout << "Player 1 won with " << count1 << " books." << std::endl;
				}
				if (count2 > count1){
					std::cout << "Player 2 won with " << count2 << " books." << std::endl;
				}
				gameOver = true;
			}
		}
		playerMax("Player 2", Player2Root);

	}


}

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
	for (int i = 0; i < largest.size(); i++){
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
			std::cout << "Player one now has " << count1 << " books!" << std::endl;

		}
		if (player == "Player 2"){
			count2++;
			std::cout << "Player two now has " << count2 << " books!" << std::endl;

		}
	}

	return cardName;
}



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


bool GoFish::isEmpty(){
	if (deck.empty()){
		std::cout << "Game over" << std::endl;
		return true;
	}
}
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

