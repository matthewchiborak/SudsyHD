#include "GameStateWait.h"

#include <iostream>

GameStateWait::GameStateWait(IGameModel& model)
	: GameState(model)
{
}

void GameStateWait::advance()
{
	model->getCurrentLevel()->advance();
}

void GameStateWait::move(const Point direction)
{
	model->getCurrentLevel()->move(direction);
}

void GameStateWait::interact()
{
	model->getCurrentLevel()->interact();
}

void GameStateWait::change(bool next)
{
	model->getCurrentLevel()->change(next);
}
