#include"Pieces.h"
#include "Players.h"
#include "Board.h"
using namespace std;

Pieces::Pieces(){
	this->player = 0;
}
 
Pieces::Pieces(int name){
	this->amount = 4;
	this->player = name;
}
void Pieces::setPlayer(int n){
	this->player = n;
}

int Pieces::getPlayer(){
	return this->player;
}



