#ifndef GAME_CONTEXT_H
#define GAME_CONTEXT_H

#include <memory>

#include "../Point.h"
#include "GameState.h"

class GameContext
{
public:
	GameContext();

	void advance();
	void move(const Point direction);
	void interact();

	void setState(std::unique_ptr<GameState> state);

private:
	std::unique_ptr<GameState> state;
};

#endif