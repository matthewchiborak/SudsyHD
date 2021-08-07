#include "IGameModel.h"

#include <iostream>

IGameModel::IGameModel(ILevelFactory& levelFactory)
	: levelFactory(&levelFactory)
{
}

void IGameModel::loadLevel(int level)
{
	try
	{
		currentLevel = levelFactory->createLevel(level);
	}
	catch (std::exception e)
	{
		std::cout << "Load Level Error\n";
	}
}
