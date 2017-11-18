#include "Board.h"
#include <iostream>
using namespace std;

Board:: Board(Players *p1,Players *p2) {
	
	this->player1 = p1;
	this->player2 = p2;
	this->size = 32;
	bArray = new Blocks[size];
	for (int i = 0; i < size; i++) {
		bArray[i].setID(i); 
	}
}

Board:: Board(Players *p1,Players *p2,Players *p3) { //Inititializes 3 player objects
	this->player1 = p1;
	this->player2 = p2;
	this->player3 = p3;
	this->size = 32;
	bArray = new Blocks[size];
	for (int i = 0; i < size; i++) {
		bArray[i].setID(i);
	}
}
Board:: Board(Players *p1,Players *p2,Players *p3,Players *p4) { //initializes 4 player objects
	this->player1 = p1;
	this->player2 = p2;
	this->player3 = p3;
	this->player4 = p4;
	this->size = 32;
	bArray = new Blocks[size];
	for (int i = 0; i < size; i++) {
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
	if(player3->getName() == name){
		return player3;
	}
	if(player4->getName() == name){
		return player4;
	}
}

int Board::getPosition(Players p){//Takes in a player object and finds its position on the boared and returns that index, -1 if not found
	int k = 0;
	// while (k<2) {
		for (int i = 0; i < size; i++) {
			if (bArray[i].getPiece().getPlayer() == p.getPieces().getPlayer()) {
				return i;
			}
		}
	k++;
	// }
	return -1;
}

void Board::addPlayer(Players p,int i) { //takes in a player object and an index
	this->bArray[i].addPiece(p.getPieces()); //Adds players piece to the players name at that index
}


bool Board::isFinished(Players p,int index){
	if(p.getPlaceBack() && index >= p.getFinish()){//and checks if the new index position is greater than or equal to the finish index
		return true; //if true means the piece made it around the board
	}
	return false;
}


void Board:: move(Players player, int roll) {
	Players *temp = this->findPlayer(player.getName());
	int oldPos = this->getPosition(*temp);
	int newPos = oldPos + roll;
	bArray[oldPos].removePiece(temp->getPieces());
	if(newPos > 31){
		newPos = newPos - 32;
		this->reachedEnd(*temp,newPos);
	}
	if(bArray[newPos].getPiece().getPlayer() != temp->getName()){
		bArray[newPos].addPiece(temp->getPieces());
	}
	if(isFinished(player,newPos)){
		bArray[newPos].removePiece(temp->getPieces());
		this->startGame(*temp);
		newPos = temp->getStart();
		int left = temp->getAmount() -1;
		temp->setAmount(left);
		temp->setPlaceBack(false);
		cout<<"Player "<<temp->getName()<<" made it around the board!!"<<endl;
		if(left != 0 ){
			cout<<"Player "<<temp->getName()<<" you have "<<left<< " pieces left!! KEEP GOING!!"<<endl;
		}
	}
	if(temp->checkWin()){
		cout<<"Player "<<temp->getName()<<" YOU WINNN!!!"<<endl;

	}
	if(bArray[newPos].getSize() == 2){
		this->jump(*temp,newPos);
	}

	

}

void Board:: reachedEnd(Players player,int index){
	Players *temp = this->findPlayer(player.getName());
	temp->setPlaceBack(true);
	bArray[index].addPiece(temp->getPieces());
}

void Board:: jump(Players player,int index){
	Players *temp = this->findPlayer(player.getName());
	Pieces p = bArray[index].getPiece();
	Players *jumped = this->findPlayer(p.getPlayer());
	bArray[index].removePiece(jumped->getPieces());
	this->startGame(*jumped);
	cout<<"Player "<<temp->getName()<<" Jumped player "<<jumped->getName()<<", Player "<<jumped->getName()<<" is now back at start"<<endl;


}
void Board::startGame(Players p){ //takes a player object
	int start = p.getStart(); //gets the start index of the player
	bArray[start].addPiece(p.getPieces());
}

Blocks* Board:: getBlocks(int id){
	for(int i = 0; i < size; i++){
		if (bArray[i].getID() == id) {
			return &bArray[i];
		}
	}
	return nullptr;
}

void Board:: print() {
	// bArray[0].addPiece(player1->getPieces());
	// bArray[0].addPiece(player2->getPieces());
	// bArray[4].removePiece(player1->getPieces());
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

		// if(array[j].getPlayer() == 0 && array[j+k].getPlayer() == 0){
		// 	cout<<"|   |\t\t    |   |"<<endl;
		// }
		// if(array[j].getPlayer() != 0 && array[j+k].getPlayer() !=0){
		// 	cout<<"| "<<array[j].getPlayer()<<" |\t\t    | "<<array[j+k].getPlayer()<<" |"<<endl;
		// }
		// if(array[j].getPlayer() !=0 && array[j+k].getPlayer() == 0){
		// 	cout<<"| "<<array[j].getPlayer()<<" |\t\t    |   |"<<endl;
		// }
		// if(array[j].getPlayer() == 0 && array[j+k].getPlayer() !=0) {
		// 	cout<<"|   |\t\t    | "<<array[j+k].getPlayer()<<" |"<<endl;
		// }
		/*cout << "|" << (array[j] == 0?" ":array[j])<< "|" << "\t    " 
		<< "|" << (array[j+k] == 0?" ":array[j+k]) << "|" << endl;*/
		k += 2;
	}
	for (int l = 8; l >= 0; l--) {
		bArray[l].print();
	}
	cout << endl;
}




