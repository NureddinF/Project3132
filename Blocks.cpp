//Blocks class
//Board has blocks (has a relationship)
#include "Blocks.h"
#include <iostream>
using namespace std;

Blocks:: Blocks() {
	this->size = 0;
	pArray = new Pieces[2];
}

Blocks:: ~Blocks() {
	 
}

void Blocks:: addPiece(Pieces piece) {
	pArray[size] = piece;
	size++;
}

void Blocks:: removePiece(Pieces piece) {
	Pieces defaultP = Pieces();
	if (pArray[0].getPlayer() == piece.getPlayer()) {
		if(pArray[1].getPlayer() == 0){
			pArray[0] = defaultP;
		}
		else{
			pArray[0] = pArray[1];
			pArray[1] = defaultP;
		}
		
	}
	else if (pArray[1].getPlayer() == piece.getPlayer()) {
		pArray[1] = defaultP;
	}
	size--;
}


Pieces Blocks:: getPiece() {
	return pArray[0];
}

int Blocks:: getSize() {
	return this->size;
}


void Blocks:: print() {
	cout<<"| ";
	for (int i = 0; i < size; i++) {
		if(pArray[i].getPlayer() == 0){
			cout<<"";

		}
		else{
			cout << pArray[i].getPlayer();
		}
	}
	cout<<" |";
}

void Blocks:: setID(int id){
	this->id = id;
}

int Blocks:: getID(){
	return this->id;
}

int Blocks:: checkBlocks(int name) {
	for (int i = 0; i < size; i++) {
		if (pArray[i].getPlayer() == name) {
			return i;
		}
	}
	return -1;
}

