#ifndef PLAYERS_H
#define PLAYERS_H
#include <iostream>
using namespace std;
#include "Pieces.h"
#include "Dice.h"

class Players {
protected:
	int name; //name of the player (1,2,3, or 4)
	int start; //start index for the player
	int finish; //finish index of the player
	Pieces *p;   //Pieces object
	bool placeBack; //boolean variable, it is true only when the piece reaches th eend of the board and gets places back
	int amount; //amount of pieces corresponding the a player (4)
	Dice *d; //Players dice object

public:
	Players();
	Players(int name);
	
	void setName(int name);
	int getName();	
	
	int getStart();
	int getFinish();

	void setPieces(Pieces p);
	Pieces getPieces();

	bool checkWin();

	void setPlaceBack(bool i);
	bool getPlaceBack();

	int getAmount();
	void setAmount(int x);

	Dice getDice();

	void print();


};

#endif