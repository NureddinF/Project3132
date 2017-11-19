#include "Dice.h"
#include<cstdlib>
#include<ctime>


using namespace std;

Dice::Dice(){ 
	srand(time(0));
	
}
int Dice::roll(){ 
	random = rand()%6; //gets a random number from 0 to 6
	return number[random]; //returns a number from the array at index random
}