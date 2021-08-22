#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "../Point.h"
#include "../IGameModel.h"

class IView;

class GameState
{
public:
	GameState(IGameModel& model, IView& view);

	virtual void advance() = 0;
	virtual void move(const Point direction) = 0;
	virtual void interact() = 0;
	virtual void change(bool next) = 0;
	virtual void menuChange(bool next) = 0;

protected:
	IGameModel* model;
	IView* view;
	int framesPassed;
};

#endif