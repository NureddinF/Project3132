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
	Players *p3;
	Players *p4;

	Board *b;

	Dice d = Dice(); 

	cout<<"WELCOME TO SORRY!!"<<endl;
	cout<<"   "<<endl;
	cout<<"How many players would like to play?"<<endl;
	int num;

	cout<<"1. One player\n2. Two players\n3. Three Players\n4. Four Players\n";
	cin>>num;


	if(num == 1){
		cout<<"Pick your piece 1,2,3, or 4!"<<endl;
		int piece;
		cin>>piece;
		p1 = new ComputerPlayer(piece);
		cout<<"Pick your piece 1,2,3, or 4!"<<endl;
		cin>>piece;
		p2 = new HumanPlayer(piece);
		Board *b = new Board(p1,p2);
		b->startGame(*p1);
		b->startGame(*p2);
		cout<<"Your pieces are now on your start blocks! GOOD LUCK!!"<<endl;
		b->print();
		int roll;
		bool check1 = p1->checkWin();
		bool check2 = p2->checkWin();
		cin.ignore();
		while(check1 != true || check2 != true){

			roll = d.roll();
			
			cout<<"Player "<<p1->getName()<<" hit enter to roll!!"<<endl;
			if(cin.get() == '\n'){
				cout<<"Player "<<p1->getName()<<" you rolled a "<<roll<<endl;
				b->move(*p1,roll);
				b->print();
			}

			roll = d.roll();
			cout<<"Player "<<p2->getName()<<" hit enter to roll!!"<<endl;
			
			if(cin.get() == '\n'){
				cout<<"Player "<<p2->getName()<<" you rolled a "<<roll<<endl;
				b->move(*p2,roll);
				b->print();
			}

			check1 = p1->checkWin();
			check2 = p2->checkWin();
		}
	}

	/***DONE****/

	if(num == 2){
		cout<<"Pick your piece 1,2,3, or 4!"<<endl;
		int piece;
		cin>>piece;
		p1 = new Players(piece);
		cout<<"Pick your piece 1,2,3, or 4!"<<endl;
		cin>>piece;
		p2 = new Players(piece);
		Board *b = new Board(p1,p2);
		b->startGame(*p1);
		b->startGame(*p2);
		cout<<"Your pieces are now on your start blocks! GOOD LUCK!!"<<endl;
		b->print();
		int roll;
		bool check1 = p1->checkWin();
		bool check2 = p2->checkWin();
		cin.ignore();
		while(check1 != true || check2 != true){

			roll = d.roll();
			
			cout<<"Player "<<p1->getName()<<" hit enter to roll!!"<<endl;
			if(cin.get() == '\n'){
				cout<<"Player "<<p1->getName()<<" you rolled a "<<roll<<endl;
				b->move(*p1,roll);
				b->print();
			}

			roll = d.roll();
			cout<<"Player "<<p2->getName()<<" hit enter to roll!!"<<endl;
			
			if(cin.get() == '\n'){
				cout<<"Player "<<p2->getName()<<" you rolled a "<<roll<<endl;
				b->move(*p2,roll);
				b->print();
			}

			check1 = p1->checkWin();
			check2 = p2->checkWin();
		}
	}

	if(num == 3){
		cout<<"Pick your piece 1,2,3, or 4!"<<endl;
		int piece;
		cin>>piece;
		p1 = new Players(piece);
		cout<<"Pick your piece 1,2,3, or 4!"<<endl;
		cin>>piece;
		p2 = new Players(piece);
		Board *b = new Board(p1,p2);
		b->startGame(*p1);
		b->startGame(*p2);
		cout<<"Your pieces are now on your start blocks! GOOD LUCK!!"<<endl;
		b->print();
		int roll;
		bool check1 = p1->checkWin();
		bool check2 = p2->checkWin();
		cin.ignore();
		while(check1 != true || check2 != true){

			roll = d.roll();
			
			cout<<"Player "<<p1->getName()<<" hit enter to roll!!"<<endl;
			if(cin.get() == '\n'){
				cout<<"Player "<<p1->getName()<<" you rolled a "<<roll<<endl;
				b->move(*p1,roll);
				b->print();
			}

			roll = d.roll();
			cout<<"Player "<<p2->getName()<<" hit enter to roll!!"<<endl;
			
			if(cin.get() == '\n'){
				cout<<"Player "<<p2->getName()<<" you rolled a "<<roll<<endl;
				b->move(*p2,roll);
				b->print();
			}

			check1 = p1->checkWin();
			check2 = p2->checkWin();
		}
	}

	if(num == 4){
		cout<<"Pick your piece 1,2,3, or 4!"<<endl;
		int piece;
		cin>>piece;
		p1 = new Players(piece);
		cout<<"Pick your piece 1,2,3, or 4!"<<endl;
		cin>>piece;
		p2 = new Players(piece);
		Board *b = new Board(p1,p2);
		b->startGame(*p1);
		b->startGame(*p2);
		cout<<"Your pieces are now on your start blocks! GOOD LUCK!!"<<endl;
		b->print();
		int roll;
		bool check1 = p1->checkWin();
		bool check2 = p2->checkWin();
		cin.ignore();
		while(check1 != true || check2 != true){

			roll = d.roll();
			
			cout<<"Player "<<p1->getName()<<" hit enter to roll!!"<<endl;
			if(cin.get() == '\n'){
				cout<<"Player "<<p1->getName()<<" you rolled a "<<roll<<endl;
				b->move(*p1,roll);
				b->print();
			}

			roll = d.roll();
			cout<<"Player "<<p2->getName()<<" hit enter to roll!!"<<endl;
			
			if(cin.get() == '\n'){
				cout<<"Player "<<p2->getName()<<" you rolled a "<<roll<<endl;
				b->move(*p2,roll);
				b->print();
			}

			check1 = p1->checkWin();
			check2 = p2->checkWin();
		}
	}

	cout<<"GAME OVER!!!"<<endl;

	return 0;
}