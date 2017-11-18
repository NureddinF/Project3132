#include "Players.h"
#include "Board.h"
#include "Pieces.h"
#include <iostream>

Players:: Players() {
	this->name = 0;
	this->turn = 0;
	this->amount = 0;
	p = new Pieces(name);
}

Players:: Players(int name) {
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
	placeBack = false;
}



void Players:: setName(int name) {
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

int Players:: getName() {
	return this->name;
}

void Players:: setTurn(int turn) {
	this->turn = turn;
}

int Players:: getTurn() {
	return this->turn;
}

Pieces Players::getPieces() {
	return *p;
}

bool Players:: checkWin() {
	if (this->getAmount() == 0) {
		return true;
	}
	else {
		return false;
	}
}

int Players::getStart(){
	return start;
}
int Players::getFinish(){
	return finish;
}

void Players::setPlaceBack(bool i){
	this->placeBack = i;
}

bool Players::getPlaceBack(){
	return placeBack;
}

int Players::getAmount(){
	return amount;
}

void Players::setAmount(int x){
	this->amount = x;
}

