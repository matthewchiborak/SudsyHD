#ifndef GAME_STATE_ACTION_H
#define GAME_STATE_ACTION_H

#include "GameState.h"

class GameStateAction: public GameState
{
public:
	GameStateAction(IGameModel& model);

	void advance() override;
	void move(const Point direction) override;
	void interact() override;
	void change(bool next) override;
};

#endif