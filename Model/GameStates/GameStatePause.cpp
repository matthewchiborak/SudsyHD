#include "GameStatePause.h"

#include "GameStateWait.h"

GameStatePause::GameStatePause(IGameModel& model)
	: GameState(model)
{
}

void GameStatePause::advance()
{
}

void GameStatePause::move(const Point direction)
{
}

void GameStatePause::interact()
{
}

void GameStatePause::change(bool next)
{
}

void GameStatePause::menuChange(bool next)
{
	this->model->setState(std::move(std::make_unique<GameStateWait>(*model)));
}
