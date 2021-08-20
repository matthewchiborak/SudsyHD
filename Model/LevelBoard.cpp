#include "LevelBoard.h"

#include <iostream>

LevelBoard::LevelBoard()
	: Level()
{
}

void LevelBoard::advance(float t)
{
	for (int i = 0; i < boardObjects.size(); i++)
	{
		boardObjects[i].get()->advance(t, *(this));
	}

	this->cleanUpBoardObjects();
}

bool LevelBoard::move(const Point direction)
{
	return this->moveCommand.get()->execute(direction);
}

bool LevelBoard::interact()
{
	return this->interactCommand.get()->execute();
}

void LevelBoard::change(bool next)
{
	if (next)
		this->changeNextCommand.get()->execute();
	else
		this->changePrevCommand.get()->execute();
}

void LevelBoard::handleCollisions()
{
	//If 2 objects on the same space, check space claim ids. Destroy objects as neccessary
	for (int i = 0; i < boardObjects.size() - 1; i++)
	{
		for (int j = i + 1; j < boardObjects.size(); j++)
		{
			if (boardObjects.at(i).get()->getPosition() == boardObjects.at(j).get()->getPosition())
			{
				removeOrKeepObjectsOnSameSpace(i, j);
			}
		}
	}
}

bool LevelBoard::isAtLeastOneOfObjectTypeAlive(std::string key) const
{
	for (int i = 0; i < this->boardObjects.size(); i++)
	{
		if (boardObjects[i].get()->getSpaceSharingKey() == key)
			return true;
	}

	return false;
}

void LevelBoard::setMoveCommand(std::unique_ptr<LevelCommandPoint> cmd)
{
	this->moveCommand = std::move(cmd);
}

void LevelBoard::setInteractCommand(std::unique_ptr<LevelCommand> cmd)
{
	this->interactCommand = std::move(cmd);
}

void LevelBoard::setChangeNextCommand(std::unique_ptr<LevelCommand> cmd)
{
	this->changeNextCommand = std::move(cmd);
}

void LevelBoard::setChangePrevCommand(std::unique_ptr<LevelCommand> cmd)
{
	this->changePrevCommand = std::move(cmd);
}

void LevelBoard::removeOrKeepObjectsOnSameSpace(int& i, int& j)
{
	std::string key = boardObjects[i].get()->getSpaceSharingKey();

	if (key == "Person")
	{
		handlePeopleCollisions(i, j);
		return;
	}
	if (key == "Enemy")
	{
		handleEnemyCollisions(i, j);
		return;
	}
	if (key == "Rock")
	{
		handleRockCollisions(i, j);
		return;
	}
	if (key == "Rock-Float")
	{
		handleRockFloatCollisions(i, j);
		return;
	}
	if (key == "Arrow")
	{
		handleArrowCollisions(i, j);
		return;
	}
	if (key == "Pit")
	{
		handleHoleCollisions(i, j);
		return;
	}
	if (key == "Goal")
	{
		handleGoalCollisions(i, j);
		return;
	}
}

void LevelBoard::handlePeopleCollisions(int& i, int& j)
{
	std::string key = boardObjects[j].get()->getSpaceSharingKey();

	if (key == "Enemy" || key == "Rock" || key == "Rock-Float")
	{
		boardObjects.erase(boardObjects.begin() + i);
		resetIndices(i, j);
		return;
	}

	if (key == "Arrow")
	{
		boardObjects.erase(boardObjects.begin() + j);
		boardObjects.erase(boardObjects.begin() + i);
		resetIndices(i, j);
		resetIndices(i, j);
		return;
	}

	if (key == "Goal")
	{
		boardObjects.erase(boardObjects.begin() + j);
		resetIndices(i, j);
		return;
	}
}

void LevelBoard::handleEnemyCollisions(int& i, int& j)
{
	std::string key = boardObjects[j].get()->getSpaceSharingKey();

	if (key == "Rock" || key == "Rock-Float")
	{
		boardObjects.erase(boardObjects.begin() + i);
		resetIndices(i, j);
		return;
	}

	if (key == "Person")
	{
		boardObjects.erase(boardObjects.begin() + j);
		resetIndices(i, j);
		return;
	}

	if (key == "Arrow")
	{
		boardObjects.erase(boardObjects.begin() + j);
		boardObjects.erase(boardObjects.begin() + i);
		resetIndices(i, j);
		resetIndices(i, j);
		return;
	}
}

void LevelBoard::handleRockCollisions(int& i, int& j)
{
	std::string key = boardObjects[j].get()->getSpaceSharingKey();

	if (key == "Pit")
	{
		boardObjects.erase(boardObjects.begin() + j);
		boardObjects.erase(boardObjects.begin() + i);
		resetIndices(i, j);
		resetIndices(i, j);
		return;
	}

	if (key == "Person" || key == "Enemy")
	{
		boardObjects.erase(boardObjects.begin() + j);
		resetIndices(i, j);
	}
}

void LevelBoard::handleRockFloatCollisions(int& i, int& j)
{
	std::string key = boardObjects[j].get()->getSpaceSharingKey();

	if (key == "Person" || key == "Enemy")
	{
		boardObjects.erase(boardObjects.begin() + j);
		resetIndices(i, j);
	}
}

void LevelBoard::handleArrowCollisions(int& i, int& j)
{
	std::string key = boardObjects[j].get()->getSpaceSharingKey();

	if (key == "Person" || key == "Enemy")
	{
		boardObjects.erase(boardObjects.begin() + j);
		boardObjects.erase(boardObjects.begin() + i);
		resetIndices(i, j);
		resetIndices(i, j);
	}
}

void LevelBoard::handleHoleCollisions(int& i, int& j)
{
	std::string key = boardObjects[j].get()->getSpaceSharingKey();

	if (key == "Rock")
	{
		boardObjects.erase(boardObjects.begin() + j);
		boardObjects.erase(boardObjects.begin() + i);
		resetIndices(i, j);
		resetIndices(i, j);
		return;
	}
}

void LevelBoard::handleGoalCollisions(int& i, int& j)
{
	std::string key = boardObjects[j].get()->getSpaceSharingKey();

	if (key == "Person")
	{
		boardObjects.erase(boardObjects.begin() + i);
		resetIndices(i, j);
		return;
	}
}

void LevelBoard::resetIndices(int& i, int& j)
{
	i--;
	j = boardObjects.size() + 1;
}
