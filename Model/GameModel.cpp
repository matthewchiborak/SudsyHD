#include "GameModel.h"

GameModel::GameModel()
	: IGameModel()
{
}

void GameModel::advance()
{
	context.request();
}
