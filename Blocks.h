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
		// string color;	//the color of the block
		// Pieces pArray[2]; //store pieces in a block

		Pieces *pArray;
	
	public:
		Blocks();
		~Blocks();

		// int getIndex();
		// void setIndex(int index);
		// string getColor();
		// void setColor(string color);
		// Pieces getPiece(int index);
		// void print(int index);

		// void storePiece(Pieces piece);

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