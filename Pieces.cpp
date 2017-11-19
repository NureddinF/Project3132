#include"Pieces.h"
#include "Players.h"
#include "Board.h"
using namespace std;

Pieces::Pieces(){ //initializes player name to 0 for a default pieces
	this->player = 0;
}
  
Pieces::Pieces(int name){ // if name passed through, sets player name to name, and initializes amount to 4( 4 pieces per player)
	this->amount = 4;
	this->player = name;
}
void Pieces::setPlayer(int n){ //seters sand getters for player name
	this->player = n;
}

int Pieces::getPlayer(){
	return this->player;
}



