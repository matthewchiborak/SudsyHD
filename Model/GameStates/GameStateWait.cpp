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

	this->model->setState(std::move(std::make_unique<GameStateAction>(*model)));
}

void GameStateWait::interact()
{
	model->getCurrentLevel()->interact();

	this->model->setState(std::move(std::make_unique<GameStateAction>(*model)));
}

void GameStateWait::change(bool next)
{
	model->getCurrentLevel()->change(next);
}
