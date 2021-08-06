#ifndef GAME_STATE_H
#define GAME_STATE_H

class GameState
{
public:
	GameState();

	virtual void handle() = 0;
};

#endif