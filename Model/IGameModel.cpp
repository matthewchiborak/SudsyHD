#include "IGameModel.h"

#include <iostream>

#include "GameStates/GameState.h"

IGameModel::IGameModel(ILevelFactory& levelFactory)
	: levelFactory(&levelFactory)
{
}

void IGameModel::loadLevel(int level)
{
	try
	{
		currentLevel = levelFactory->createLevel(level);
		currentLevelNumber = level;
	}
	catch (std::exception e)
	{
		std::cout << "Load Level Error\n";
	}
}

void IGameModel::reloadCurrentLevel()
{
	this->loadLevel(currentLevelNumber);
}

void IGameModel::loadNextLevel()
{
	this->loadLevel(++currentLevelNumber);
}

Level* IGameModel::getCurrentLevel() const
{
	return currentLevel.get();
}

void IGameModel::setState(std::unique_ptr<GameState> state)
{
	this->state = std::move(state);
}
