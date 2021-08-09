#include "GameModel.h"

#include "GameStates/GameStateWait.h"

GameModel::GameModel(ILevelFactory& levelFactory)
	: IGameModel(levelFactory), state(std::make_unique<GameStateWait>(*this))
{
}

void GameModel::move(const Point direction)
{
	this->state.get()->move(direction);
}

void GameModel::interact()
{
	this->state.get()->interact();
}

void GameModel::advance()
{
	this->state.get()->advance();
}

void GameModel::change(bool next)
{
	this->state.get()->change(next);
}

void GameModel::setState(std::unique_ptr<GameState> state)
{
	this->state = std::move(state);
}
