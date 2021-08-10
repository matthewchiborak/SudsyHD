#include "GameStateWait.h"

#include <iostream>

#include "GameStateAction.h"

GameStateWait::GameStateWait(IGameModel& model)
	: GameState(model)
{
}

void GameStateWait::advance()
{

}

void GameStateWait::move(const Point direction)
{
	model->getCurrentLevel()->move(direction);
	//Change state
	this->model->setState(std::move(std::make_unique<GameStateAction>(*model)));
}

void GameStateWait::interact()
{
	model->getCurrentLevel()->interact();
}

void GameStateWait::change(bool next)
{
	model->getCurrentLevel()->change(next);
}
