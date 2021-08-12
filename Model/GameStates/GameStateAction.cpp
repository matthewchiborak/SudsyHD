#include "GameStateAction.h"

#include "GameStateWait.h"

GameStateAction::GameStateAction(IGameModel& model)
	: GameState(model)
{
}

void GameStateAction::advance()
{
	std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
	float t = (float)std::chrono::duration_cast<std::chrono::milliseconds>(now - timeStateBegan).count() / 1000.0f;
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
