#ifndef GAME_STATE_WIN_H
#define GAME_STATE_WIN_H

#include "GameState.h"

class GameStateWin: public GameState
{
public:
	GameStateWin(IGameModel& model);

	void advance() override;
	void move(const Point direction) override;
	void interact() override;
	void change(bool next) override;
};

#endif