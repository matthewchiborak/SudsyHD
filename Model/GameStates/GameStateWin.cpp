#include "GameStateWin.h"

#include "GameStateWait.h"

GameStateWin::GameStateWin(IGameModel& model)
	: GameState(model)
{
}

void GameStateWin::advance()
{
}

void GameStateWin::move(const Point direction)
{
}

void GameStateWin::interact()
{
	this->model->loadNextLevel();
	this->model->setState(std::move(std::make_unique<GameStateWait>(*model)));
}

void GameStateWin::change(bool next)
{
}
