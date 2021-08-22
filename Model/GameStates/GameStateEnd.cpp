#include "GameStateEnd.h"

#include "../../View/IView.h"

GameStateEnd::GameStateEnd(IGameModel& model, IView& view)
	: GameState(model, view)
{
	view.setRenderingStrategy("End");
}

void GameStateEnd::advance()
{
}

void GameStateEnd::move(const Point direction)
{
}

void GameStateEnd::interact()
{

}

void GameStateEnd::change(bool next)
{
}

void GameStateEnd::menuChange(bool next)
{
}
