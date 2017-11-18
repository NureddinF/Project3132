//Dice class
//Board has dice (has a relationship)
#ifndef DICE_H
#define DICE_H
using namespace std;

class Dice{
protected:
	int number[6] = {1,2,3,4,5,6};
	int random;

public:
	Dice(); 
	int roll();
};

#endif