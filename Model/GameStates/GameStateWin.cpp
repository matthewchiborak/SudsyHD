#include "GameStateWin.h"

#include "GameStateWait.h"
#include "GameStateEnd.h"

#include "../../View/IView.h"

GameStateWin::GameStateWin(IGameModel& model, IView& view)
	: GameState(model, view)
{
	view.setRenderingStrategy("Win");
}

void GameStateWin::advance()
{
}

void GameStateWin::move(const Point direction)
{
}

void GameStateWin::interact()
{
	if(this->model->loadNextLevel())
		this->model->setState(std::move(std::make_unique<GameStateWait>(*model, *view)));
	else
		this->model->setState(std::move(std::make_unique<GameStateEnd>(*model, *view)));
}

void GameStateWin::change(bool next)
{
}

void GameStateWin::menuChange(bool next)
{
}
