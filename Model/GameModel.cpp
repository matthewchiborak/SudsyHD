#include "GameModel.h"

GameModel::GameModel(ILevelFactory& levelFactory)
	: IGameModel(levelFactory)
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

