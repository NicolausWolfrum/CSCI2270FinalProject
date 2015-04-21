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

};

class GoFish
{

public:
	GoFish();
	virtual ~GoFish();
	void addCard(std::string, int);
	void shuffleDeck();

private:
	std::vector <card*> deck;
};

#endif // GOFISH_H

