#ifndef PIECES_H
#define PIECES_H


class Pieces {
protected:
	int player;
	int amount;
public:
	Pieces();
	Pieces(int name); 
	void setPlayer(int n);
	int getPlayer();

};
#endif