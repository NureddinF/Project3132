#include "Board.h"
#include "Players.h"
#include "Dice.h"
#include "Pieces.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include <iostream>

using namespace std;

int main(void) {
	Players *p1;
	Players *p2;
	Board *b;

	cout<<"WELCOME TO SORRY!!"<<endl;
	cout<<"   "<<endl;
	cout<<"How many players would like to play?"<<endl;
	int num;

	cout<<"1. One player\n2. Two players\n";
	cin>>num;

	if(num == 1){
		int piece1,piece2;
		cout << "Choose where you want to start." << endl;
		b->printDemo(); //show all the start positions and finish positions on the board
		cout<<"Pick your piece 1,2,3, or 4!"<<endl;
		cin>>piece1;
		cout<<"Pick a piece for the computer 1,2,3, or 4!"<<endl;
		cin>>piece2;

		while(piece1 == piece2){
			cout<<"Sorry!! pieces must be different."<<endl;
			cout<<"Try again."<<endl;

			cout<<"Pick your piece 1,2,3, or 4!"<<endl;
			cin>>piece1;
			cout<<"Pick a piece for the computer piece 1,2,3, or 4!"<<endl;
			cin>>piece2;
		}

		p1 = new ComputerPlayer(piece1);
		p2 = new HumanPlayer(piece2);
		Board *b = new Board(p1,p2);

		b->startGame(*p1);
		b->startGame(*p2);
		cout<<"Your pieces are now on your start blocks! GOOD LUCK!!"<<endl;
		b->print();
		int roll1,roll2;
		bool check1 = p1->checkWin();
		bool check2 = p2->checkWin();
		cin.ignore();
		while(check1 == false && check2 == false){

			roll1 = p1->getDice().roll();
			
			cout<<"Player "<<p1->getName()<<" hit enter to roll!!"<<endl;

			if(cin.get() == '\n'){
				cout<<"Player "<<p1->getName()<<" you rolled a "<<roll1<<endl;
				b->move(*p1,roll1);
				b->print();
			}
			check1 = p1->checkWin();

			roll2 = p2->getDice().roll();
			cout<<"Player "<<p2->getName()<<" turn!!"<<endl;
			cout<<"Player "<<p2->getName()<<" rolled a "<<roll2<<endl;
			b->move(*p2,roll2);
			b->print();
			check2 = p2->checkWin();
		}

		if (check1) {
			cout<<"Player "<<p1->getName()<<" YOU WINNN!!!"<<endl;
		}
		if (check2) {
			cout<<"Player "<<p2->getName()<<" YOU WINNN!!!"<<endl;
		}
	}

	if(num == 2){
		int piece1,piece2;
		cout << "Choose where you want to start." << endl;
		b->printDemo(); //show all the start positions and finish positions on the board
		cout<<"Pick your piece 1,2,3, or 4!"<<endl;
		cin>>piece1;
		cout<<"Pick your piece 1,2,3, or 4!"<<endl;
		cin>>piece2;

		while(piece1 == piece2){
			cout<<"Sorry!! pieces must be different."<<endl;
			cout<<"Try again."<<endl;

			cout<<"Pick your piece 1,2,3, or 4!"<<endl;
			cin>>piece1;
			cout<<"Pick your piece 1,2,3, or 4!"<<endl;
			cin>>piece2;
		}

		p1 = new HumanPlayer(piece1);
		p2 = new HumanPlayer(piece2);
		Board *b = new Board(p1,p2);
		b->startGame(*p1);
		b->startGame(*p2);
		cout<<"Your pieces are now on your start blocks! GOOD LUCK!!"<<endl;
		b->print();
		int roll1, roll2;
		bool check1 = p1->checkWin();
		bool check2 = p2->checkWin();
		cin.ignore();
		while(check1 == false && check2 == false){

			roll1 = p1->getDice().roll();
			
			cout<<"Player "<<p1->getName()<<" hit enter to roll!!"<<endl;
			if(cin.get() == '\n'){
				cout<<"Player "<<p1->getName()<<" you rolled a "<<roll1<<endl;
				b->move(*p1,roll1);
				b->print();
			}
			check1 = p1->checkWin();

			roll2 = p2->getDice().roll();
			
			cout<<"Player "<<p2->getName()<<" hit enter to roll!!"<<endl;
			
			if(cin.get() == '\n'){
				cout<<"Player "<<p2->getName()<<" you rolled a "<<roll2<<endl;
				b->move(*p2,roll2);
				b->print();
			}
			check2 = p2->checkWin();
		}

		if (check1) {
			cout<<"Player "<<p1->getName()<<" YOU WINNN!!!"<<endl;
		}
		if (check2) {
			cout<<"Player "<<p2->getName()<<" YOU WINNN!!!"<<endl;
		}
	}
	cout<<"GAME OVER!!!"<<endl;
	return 0;
}