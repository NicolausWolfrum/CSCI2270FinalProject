# CSCI2270FinalProject
Nicolaus Wolfrum & Elliot Benson's CSCI 2270 Final Project

Project Summary: Our project was to write a program for a "Go Fish" game. Using an assortment of data structures and other C++ methods that we learned over the course of the semester, our program reads in a pre-created file with a standard deck of cards excluding jokers. The program then "shuffles" the cards using an array shuffling algorithm, and "deals" seven cards to each player (The game is played as one player vs. the computer. Time permitting we may be able to make a player vs player option) After the cards are dealt, the game is played like standard "Go Fish", where each player takes turns attempting to get four cards of the same number (ex. four "aces"). The program searches the other players cards for the desired card number and returns the cards if found to the first player. If not found, the second player says "Go Fish", and the first player draws a card from the pool. The game is played until the pool is empty, and at the end the score is totaled based on who has the most sets of four. The program will use an assortment of arrays, linked lists, vectors, and structs to achieve this.

How is Go Fish Played?

	Cards must be shuffled before they are dealt to the players.
	Since we are only going to be using two players, each player will be dealt 7 cards.
	Dealer deals cards clockwise, face down (a function to reveal cards). Remainder of 
	pack is placed in center deck for drawing.
	Goal is to get most books/sets of four (so need to count when we have four of a 			
	kind) Will need to subtract if user loses a card that was in a book.
	When a asking/fishing for a card, the user must have that type of card in his/her 			
	hand. So need to check if that card is in the hand.
	If player asked doesn’t have the requested card, cout<<“GO FISH”<<endl; and the user must
	draw a card from the deck.	
	If the card is found, the user can ask the same player or another player for more cards, 		
	essentially, his turn continues. If he makes a catch, the card must be revealed
	Once a player gains the fourth card of a book, the book is revealed face up and can no 			
	longer be accessed.
	If a catch is not made, the turn goes to the player to the left.
	

How to Run:
Compile/Build an run the program. Once running, you need to go through the steps. It will ask you to shuffle the cards, deal the cards,
and reveal your cards. At this point, you are able to "Go Fish". Then it will prompt you for what card you are looking for, and you should enter an integer between 
1 and 13. The computer will automatically go after this. The game is supposed to run until all cards are gone, or until you press 5 (the option to quit).

Dependencies: Uses basic/standard c++ libraries. No third party content needed.

System Requirements: For starters, the program will run on just Windows operating systems, will 	improve to Linux, but won’t likely go to Mac. (This will be updated with a final 		decision)

Group Members: Elliot Benson & Nic Wolfrum

Contributors: N/A

Open Issues/Bugs:

	No consistent issues known of. 
		



