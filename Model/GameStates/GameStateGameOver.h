#ifndef GAME_STATE_GAME_OVER_H
#define GAME_STATE_GAME_OVER_H

#include "GameState.h"

class GameStateGameOver: public GameState
{
public:
	GameStateGameOver(IGameModel& model, IView& view);

	void advance() override;
	void move(const Point direction) override;
	void interact() override;
	void change(bool next) override;
	void menuChange(bool next) override;
};

#endif