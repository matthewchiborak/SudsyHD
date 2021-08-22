#ifndef GAME_STATE_END_H
#define GAME_STATE_END_H

#include "GameState.h"

class GameStateEnd: public GameState
{
public:
	GameStateEnd(IGameModel& model, IView& view);

	void advance() override;
	void move(const Point direction) override;
	void interact() override;
	void change(bool next) override;
	void menuChange(bool next) override;
};

#endif