#include "GameModel.h"

GameModel::GameModel(ILevelFactory& levelFactory)
	: IGameModel(levelFactory)
{
}

void GameModel::move(const Point direction)
{
	context.move(direction);
}

void GameModel::interact()
{
	context.interact();
}

void GameModel::advance()
{
	context.advance();
}
