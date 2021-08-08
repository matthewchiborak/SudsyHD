#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "../Point.h"

class GameState
{
public:
	GameState();

	virtual void advance() = 0;
	virtual void move(const Point direction) = 0;
	virtual void interact() = 0;
};

#endif