#ifndef GAME_CONTEXT_H
#define GAME_CONTEXT_H

#include <memory>

#include "GameState.h"

class GameContext
{
public:
	GameContext();

	void request();

	void setState(std::unique_ptr<GameState> state);

private:
	std::unique_ptr<GameState> state;
};

#endif