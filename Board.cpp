#include "Board.h"
#include <iostream>
using namespace std;

Board:: Board(Players *p1,Players *p2) { //Constructor that takes in the two player objects.
	
	this->player1 = p1; //sets the the player object to the the player object defined in the board class
	this->player2 = p2;
	this->size = 32;
	bArray = new Blocks[size]; //Initializes the blocks array
	for (int i = 0; i < size; i++) { //Initializes each block with an id
		bArray[i].setID(i); 
	}
}

Board:: ~Board() {
	delete[] bArray;
}

Players *Board::findPlayer(int name){ //Takes a name(1,2,3 or 4) and returns the player object corresponding to the name
	if(player1->getName() == name){
		return player1;
	}
	if(player2->getName() == name){
		return player2;
	}
}

int Board::getPosition(Players p){//Takes in a player object and finds its position on the boared and returns that index, -1 if not found
	for (int i = 0; i < size; i++) {
		if (bArray[i].getPiece().getPlayer() == p.getPieces().getPlayer()) {
			return i;
		}
	}
	return -1;
}

void Board::addPlayer(Players p,int i) { //takes in a player object and an index
	this->bArray[i].addPiece(p.getPieces()); //Adds players piece to the players name at that index
}


bool Board::isFinished(Players p,int index){
	Players *temp = this->findPlayer(p.getName());
	if(temp->getPlaceBack() && index >= temp->getFinish()){//and checks if the new index position is greater than or equal to the finish index
		return true; //if true means the piece made it around the board
	}
	return false;
}


void Board:: move(Players player, int roll) { //takes in a player and a roll amount
	Players *temp = this->findPlayer(player.getName()); //initializes a temporary player that calls the find function to get the player
	int oldPos = this->getPosition(*temp); 						//gets the position the piece is currently at
	int newPos = oldPos + roll; 								//finds the new postion the piece should move to
	bArray[oldPos].removePiece(temp->getPieces()); 				//removes the pieces at the old position
	if(newPos > 31){   											//Checks if the new position is greater than the size of the board
		newPos = newPos - 32; 									//Subtracts the size of the board from the new position
		this->reachedEnd(*temp,newPos); 						//calls the reachend function
	}
	if(bArray[newPos].getPiece().getPlayer() != temp->getName()){ //Check if the piece has been added at new position  
		bArray[newPos].addPiece(temp->getPieces());
	}
	if(isFinished(player,newPos)){                               //Checks if the player is finished, means the player made it around the board
		bArray[newPos].removePiece(temp->getPieces());           //removes the piece 
		this->startGame(*temp);									//Calls start games which puts the next piece on the board at their start position
		newPos = temp->getStart();
		int left = temp->getAmount() -1;						//Decrements the amount of pieces left for the player
		temp->setAmount(left);									//sets the amount to the player object
		temp->setPlaceBack(false);								//sets place back to false, placeback is true when the pieces reached the end and had to be re added to the board
		cout<<"Player "<<temp->getName()<<" made it around the board!!"<<endl;  
		if(left != 0 ){
			cout<<"Player "<<temp->getName()<<" you have "<<left<< " pieces left!! KEEP GOING!!"<<endl;
		}
	}
	if(bArray[newPos].getSize() >= 2){. //The check if the size of the pieces array is greater than = to 2
		this->jump(*temp,newPos);       //Calls the jump function
	}

}

void Board:: reachedEnd(Players player,int index){
	Players *temp = this->findPlayer(player.getName());//Finds the player
	temp->setPlaceBack(true);							//sets place back to ture
	bArray[index].addPiece(temp->getPieces());			//adds the piece
}

void Board:: jump(Players player,int index){
	Players *temp = this->findPlayer(player.getName()); 
	Pieces p = bArray[index].getPiece();				//gets the piece at the the index
	Players *jumped = this->findPlayer(p.getPlayer()); //finds the player of that pieces and store the player as the player getting jumped
	bArray[index].removePiece(jumped->getPieces());		//remove the pieces getting jumped
	bArray[index].removePiece(temp->getPieces());		//remove the piece to ensure no duplicates
	jumped->setPlaceBack(false);						//set place back to false
	this->startGame(*jumped);							//put the jumped player back at its start position
	bArray[index].addPiece(temp->getPieces());			//Add the piece back to the index
	cout<<"Player "<<temp->getName()<<" Jumped player "<<jumped->getName()<<", Player "<<jumped->getName()<<" is now back at start"<<endl;

}
void Board::startGame(Players p){ //takes a player object
	int start = p.getStart(); //gets the start index of the player
	bArray[start].addPiece(p.getPieces());
}

Blocks* Board:: getBlocks(int id){ //returns the block at the specified index
	for(int i = 0; i < size; i++){
		if (bArray[i].getID() == id) {
			return &bArray[i];
		}
	}
	return nullptr;
}

void Board:: print() {  //prints the blocks in a square shape
	for (int i = 16; i < 25; i++) {
		bArray[i].print();
	}
	cout << endl;
	int k = 10;
	for (int j = 15; j > 8; j--) {
		bArray[j].print();
		cout<<"\t\t\t        ";
		bArray[j+k].print();
		cout<<endl;

		k += 2;
	}
	for (int l = 8; l >= 0; l--) {
		bArray[l].print();
	}
	cout << endl;
}

void Board:: printDemo() {	//show all start and finish positions on board
	for (int i = 16; i < 25; i++) {
		if (i == 20) {
			cout << "|S3|";
		}
		else if (i == 19){
			cout << "|F3|";
		}
		else {
			cout << "|  |";
		}
	}
	cout << endl;
	int k = 10;
	for (int j = 15; j > 8; j--) {
		if (j == 12) {
			cout << "|S2|";
		}
		else if (j == 11){
			cout << "|F2|";
		}
		else {
			cout << "|  |";
		}
		cout<<"\t\t\t        ";
		if (j+k == 28) {
			cout << "|S4|";
		}
		else if (j+k == 27){
			cout << "|F4|";
		}
		else {
			cout << "|  |";
		}
		cout<<endl;
		k += 2;
	}
	for (int l = 8; l >= 0; l--) {
		if (l == 4) {
			cout << "|S1|";
		}
		else if (l == 3){
			cout << "|F1|";
		}
		else {
			cout << "|  |";
		}
	}
	cout << endl;
}



