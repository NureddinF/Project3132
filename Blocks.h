//Blocks class
//Board has blocks (has a relationship)
#ifndef BLOCKS_H
#define BLOCKS_H
#include "Pieces.h"
#include <iostream>
#include <deque>
using namespace std;

class Blocks { 
	protected:
		int id;	//block's id
		int size;	//the block's position on a board
		Pieces *pArray; //array of Pieces objects
	
	public:
		Blocks();
		~Blocks();

		void setID(int id);
		int getID();
		void addPiece(Pieces piece);
		void removePiece(Pieces piece);
		int checkBlocks(int name);	
		Pieces getPiece();
		int getSize();
		void print();		
};

#endif