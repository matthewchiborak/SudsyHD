#ifndef GAME_STATE_PAUSE_H
#define GAME_STATE_PAUSE_H

#include "GameState.h"

class GameStatePause: public GameState
{
public:
	GameStatePause(IGameModel& model);

	void advance() override;
	void move(const Point direction) override;
	void interact() override;
	void change(bool next) override;
	void menuChange(bool next) override;
};

#endif