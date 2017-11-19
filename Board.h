#ifndef BOARD_H
#define BOARD_H
#include "Players.h"
#include "Pieces.h"
#include "Blocks.h"

class Board {
protected:
	Blocks *bArray; //array of blocks objects
	int size; 		
	Players *player1; //player object
	Players *player2; //player objects

public:
	Board();
	Board(Players *p1,Players *p2);
	~Board();

	Players *findPlayer(int name);
	void addPlayer(Players p,int i);
	int getPosition(Players p);
	void startGame(Players p);
	bool isFinished(Players p,int index);
	void move(Players p,int roll);		
	void jump(Players player,int index);
	void reachedEnd(Players player,int index);

	void print();
	void printDemo();

	Blocks *getBlocks(int id);
};


#endif