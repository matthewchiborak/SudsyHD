#include "GameStateGameOver.h"

#include "GameStateWait.h"

#include "../../View/IView.h"

GameStateGameOver::GameStateGameOver(IGameModel& model, IView& view)
	: GameState(model, view)
{
	view.setRenderingStrategy("GameOver");
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
	this->model->setState(std::move(std::make_unique<GameStateWait>(*model, *view)));
}

void GameStateGameOver::change(bool next)
{
}

void GameStateGameOver::menuChange(bool next)
{
}
