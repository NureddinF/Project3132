#ifndef BOARD_H
#define BOARD_H
#include "Players.h"
#include "Pieces.h"
#include "Blocks.h"

class Board {
protected:
	Blocks *bArray;
	int size;
	Players *player1; 
	Players *player2;
	Players *player3;
	Players *player4;
	bool fin = false;
	// int overLapped;

public:
	Board();
	Board(Players *p1,Players *p2);
	Board(Players *p1,Players *p2,Players *p3);
	Board(Players *p1,Players *p2,Players *p3,Players *p4);
	~Board();

	Players *findPlayer(int name);
	Blocks *getBlock(int id);
	void addPlayer(Players p,int i);
	int getPosition(Players p);
	void startGame(Players p);
	bool isFinished(Players p,int index);
	void move(Players p,int roll);
	void jump(Players player,int index);
	void reachedEnd(Players player,int index);

	void print();
	Blocks *getBlocks(int id);
};


#endif