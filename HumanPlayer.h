#include "Players.h"
#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

class HumanPlayer:public Players{
protected:
	int name;
public:
	HumanPlayer(int name);
};
#endif