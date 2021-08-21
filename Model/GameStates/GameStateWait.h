#ifndef GAME_STATE_WAIT_H
#define GAME_STATE_WAIT_H

#include "GameState.h"

class GameStateWait: public GameState
{
public:
	GameStateWait(IGameModel& model);

	void advance() override;
	void move(const Point direction) override;
	void interact() override;
	void change(bool next) override;
	void menuChange(bool next) override;
};

#endif