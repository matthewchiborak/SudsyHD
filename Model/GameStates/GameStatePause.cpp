#include "GameStatePause.h"

#include "GameStateWait.h"

#include "../../View/IView.h"

GameStatePause::GameStatePause(IGameModel& model, IView& view)
	: GameState(model, view)
{
	view.setRenderingStrategy("Pause");
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
	this->model->setState(std::move(std::make_unique<GameStateWait>(*model, *view)));
}
