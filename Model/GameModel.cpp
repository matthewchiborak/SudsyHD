#include "GameModel.h"

GameModel::GameModel(ILevelFactory& levelFactory)
	: IGameModel(levelFactory)
{
}

void GameModel::advance()
{
	context.request();
}
