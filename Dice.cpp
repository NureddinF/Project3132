#include "Dice.h"
#include<cstdlib>
#include<ctime>


using namespace std;

Dice::Dice(){
	srand(time(0));
	//random = rand()%6;
	
}
int Dice::roll(){ 
	random = rand()%6;
	return number[random];
}