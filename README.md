

		# CSCI2270FinalProject
### Nicolaus Wolfrum & Elliot Benson's CSCI 2270 Final Project

#### Project Summary: 
	
	Our project was to write a program for a "Go Fish" game. Using an assortment of data structures
	and other C++ methods that we learned over the course of the semester, our program reads in a pre-created
	file with a standard deck of cards excluding jokers. The program then "shuffles" the cards using an array
	shuffling algorithm, and "deals" seven cards to each player (The game is played as one player vs. the computer.
	Time permitting we may be able to make a player vs player option) After the cards are dealt, the game is played
	like standard "Go Fish", where each player takes turns attempting to get four cards of the same number
	(ex. four "aces"). The program searches the other players cards for the desired card number and returns
	the cards if found to the first player. If not found, the second player says "Go Fish", and the first player
	draws a card from the pool. The game is played until the pool is empty, and at the end the score is totaled
	based on who has the most sets of four. The program will use an assortment of arrays, linked lists, vectors, 
	and structs to achieve this.

#### How is Go Fish Played?
	
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
	

#### How to Run:
	
	Download the "GoFish.exe" file and the "Deck.txt" file. Create a new folder, and place both files
	into the new directory. 
	Next, double click `GoFish.exe` to run the program. You will be prompted with a menu with 5 options. 
	First, shuffle the cards by typing a `1` and hitting `enter`. 
	Next, deal the cards by typing a `2` and hitting `enter`. 
	Next, reveal your cards by typing a `3` and hitting `enter`.
	Next, go fishing for a card by typing a `4` and hitting `enter`.
	Follow the basic rules until the game is over. When the game is over you will be informed that it is over. 
	At this point, type `5` and hit `enter` to quit the game.

#### Dependencies: 
	
	Uses basic/standard c++ libraries. No third party content needed.

#### System Requirements:
	 
	For starters, the program will run on just Windows operating systems, will improve to Linux, but won’t likely go to Mac. (This will be updated with a final 		decision)

#### Group Members: 
	
	Elliot Benson & Nic Wolfrum

#### Contributors:
	 
	-swifteagle303
	-trsteve
	-csalva0604
	-aetas

#### Open Issues/Bugs:
	
	At this point, there are no known issues or bugs. 
	Ideas for expansion:
		- Possibly alter the program to be able to have multiple non-computer players, or just be player vs. player.
		- Have an option to "Play Again" after the game is over.
		- Create a better algoritm for what card the computer is searching for:
			* Currently, the computer searches for whatever card it has most of (so if its not found, it keeps searching
			the same card every turn, which is kind of boring. Maybe make it so every other turn it searches for the highest card,
			and the others it just searches for a random card in the list.)
		- Make a time delay between the players going. Currently it prints out everything very quickly, but with a short delay
		it could be easier to read.
		- Make it check if the input for what the player is searching for is a card number... currently if you search for anything,
		(ex. "This is not a card number"), it will just say "card not found" and draw from the pool.
		
		

