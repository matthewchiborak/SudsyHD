#include "LevelBoard.h"

#include <iostream>

LevelBoard::LevelBoard()
	: Level()
{
}

void LevelBoard::advance(IGameModel& model)
{
	for (int i = 0; i < boardObjects.size(); i++)
	{
		boardObjects[i].get()->advance(0, model);
	}
}

void LevelBoard::move(const Point direction)
{
	this->moveCommand.get()->execute(direction);
}

void LevelBoard::interact()
{
	this->interactCommand.get()->execute();
}

void LevelBoard::change(bool next)
{
	if (next)
		this->changeNextCommand.get()->execute();
	else
		this->changePrevCommand.get()->execute();
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
