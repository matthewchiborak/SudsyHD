#include "GameStateAction.h"

#include "GameStateWait.h"

GameStateAction::GameStateAction(IGameModel& model)
	: GameState(model)
{
}

void GameStateAction::advance()
{
	framesPassed++;
	float t = (float)framesPassed / 60.0f;
	model->getCurrentLevel()->advance(t);

	if(model->getCurrentLevel()->isAllObjectDoneBehaviour())
		this->model->setState(std::move(std::make_unique<GameStateWait>(*model)));
}

void GameStateAction::move(const Point direction)
{

}

void GameStateAction::interact()
{

}

void GameStateAction::change(bool next)
{

}
