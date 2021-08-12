#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <chrono>

#include "../Point.h"
#include "../IGameModel.h"

class GameState
{
public:
	GameState(IGameModel& model);

	virtual void advance() = 0;
	virtual void move(const Point direction) = 0;
	virtual void interact() = 0;
	virtual void change(bool next) = 0;

protected:
	IGameModel* model;
	std::chrono::steady_clock::time_point timeStateBegan;
};

#endif