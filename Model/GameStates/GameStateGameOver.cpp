#include "GameStateGameOver.h"

#include "GameStateWait.h"

GameStateGameOver::GameStateGameOver(IGameModel& model)
	: GameState(model)
{
}

void GameStateGameOver::advance()
{
}

void GameStateGameOver::move(const Point direction)
{
}

void GameStateGameOver::interact()
{
	this->model->reloadCurrentLevel();
	this->model->setState(std::move(std::make_unique<GameStateWait>(*model)));
}

void GameStateGameOver::change(bool next)
{
}

void GameStateGameOver::menuChange(bool next)
{
}
