#include "GameStateAction.h"

#include "GameStateWait.h"
#include "GameStateGameOver.h"
#include "GameStateWin.h"

GameStateAction::GameStateAction(IGameModel& model)
	: GameState(model)
{
}

void GameStateAction::advance()
{
	framesPassed++;
	float t = (float)framesPassed / 60.0f;
	model->getCurrentLevel()->advance(t);

	if (model->getCurrentLevel()->isAllObjectDoneBehaviour())
	{
		this->model->getCurrentLevel()->handleCollisions();
		determineNextState();
	}
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

void GameStateAction::menuChange(bool next)
{
}

void GameStateAction::determineNextState()
{
	//If no players left, game over
	if (!this->model->getCurrentLevel()->isAtLeastOneOfObjectTypeAlive("Person"))
	{
		this->model->setState(std::move(std::make_unique<GameStateGameOver>(*model)));
		return;
	}

	//If no goals left, win
	if (!this->model->getCurrentLevel()->isAtLeastOneOfObjectTypeAlive("Goal"))
	{
		this->model->setState(std::move(std::make_unique<GameStateWin>(*model)));
		return;
	}

	this->model->setState(std::move(std::make_unique<GameStateWait>(*model)));
}
