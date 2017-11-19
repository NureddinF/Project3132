#include "Players.h"
#include "Board.h"
#include "Pieces.h"
#include <iostream>

Players:: Players() { //default confructor, sets everything to 0
	this->name = 0;
	this->amount = 0;
}

Players:: Players(int name) { //sets the name of player to name, sets the start and finish points based off of the player name
	this->name = name;
	if(name == 1){
		start = 4;
		finish = 3;
	} 
	if(name == 2){
		start = 12;
		finish = 11;
	}
	if(name == 3){
		start = 20;
		finish = 19;
	}
	if(name == 4){
		start = 28;
		finish = 27;
	}
	p = new Pieces(name);
	this->amount = 4;
	placeBack = false;  //sets placeback to false
	d = new Dice();
}

void Players:: setName(int name) { //sets naem fo player and sets start and finish points based off of player name
	this->name = name;
	if(name == 1){
		start = 4;
		finish = 3;
	}
	if(name == 2){
		start = 12;
		finish = 11;
	}
	if(name == 3){
		start = 20;
		finish = 19;
	}
	if(name == 4){
		start = 28;
		finish = 27;
	}
}

int Players:: getName() { //returns the name
	return this->name;
}

Pieces Players::getPieces() { //returns the piece of the player
	return *p;
}

bool Players:: checkWin() { //checks if the player doesnt have any pieces left, returns false otherwise.
	if (this->getAmount() == 0) {
		return true;
	}
	else {
		return false;
	}
}

int Players::getStart(){ //returns the start index of the player
	return start;
}
int Players::getFinish(){ //returns the finish index of the player
	return finish;
}

void Players::setPlaceBack(bool i){ //set the place of a place player(true or false)
	this->placeBack = i;
}

bool Players::getPlaceBack(){//returns the placeback of the player
	return placeBack;
}

int Players::getAmount(){//returns the amount of pieces of the player
	return amount;
}

void Players::setAmount(int x){//set the amount of pieces for a player
	this->amount = x;
}

Dice Players:: getDice(){ //returns the dice of the player
	return *d;
}

