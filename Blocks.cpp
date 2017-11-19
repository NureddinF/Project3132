//Blocks class
//Board has blocks (has a relationship)
#include "Blocks.h"
#include <iostream>
using namespace std;

Blocks:: Blocks() { //Initializes size to 0, and initializes the Pieces array to 2
	this->size = 0;
	pArray = new Pieces[2];
}

Blocks:: ~Blocks() {
	 
}

void Blocks:: addPiece(Pieces piece) { //adds a piece to the back of the pieces array
	if(size > 2){
		cout<<"Cannot add!"<<endl;
	}
	else{
		pArray[size] = piece;
		size++; //increments size
	}
}

void Blocks:: removePiece(Pieces piece) { //Removes a pies
	Pieces defaultP = Pieces();  //default pieces intialized to all zeros
	if (pArray[0].getPlayer() == piece.getPlayer()) { //removes the piece a the front of the array, if both pieces have the same name
		if(pArray[1].getPlayer() == 0){ //if there isnt a piece at end of the array
			pArray[0] = defaultP;  //set the piece to the default piece
		}
		else{
			pArray[0] = pArray[1]; //otherwise, set the array at 0 to the piece in the array at 1
			pArray[1] = defaultP;  //set piece at array at 1 to default
		}
		
	}
	if (pArray[1].getPlayer() == piece.getPlayer()) { //removeing the piece from the back 
		pArray[1] = defaultP;
	}
	size--; //decrement size
}


Pieces Blocks:: getPiece() {
	return pArray[0];
}

int Blocks:: getSize() {
	return this->size;
}

void Blocks:: print() {  //printing the pieces in each block
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

void Blocks:: setID(int id){ //sets id for the block
	this->id = id;
}

int Blocks:: getID(){ //return the id of a block
	return this->id;
}

int Blocks:: checkBlocks(int name) { //iterates through a block to find a piece with the matching name,and returns the position of the piece
	for (int i = 0; i < size; i++) {
		if (pArray[i].getPlayer() == name) {
			return i;
		}
	}
	return -1;
}

