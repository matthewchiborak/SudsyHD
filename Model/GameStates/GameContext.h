#ifndef GAME_CONTEXT_H
#define GAME_CONTEXT_H

#include "GameState.h"

class GameContext
{
public:
	GameContext();

	void request();

private:
	GameState* state;
};

#endif