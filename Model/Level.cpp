#include "Level.h"

#include <iostream>

Level::Level()
	: height(1), width(1)
{
}

Level::~Level()
{

}

void Level::addBoardObject(std::unique_ptr<BoardObject> object)
{
	boardObjects.push_back(std::move(object));
}

void Level::removeLastBoardObject()
{
	boardObjects.erase(boardObjects.end());
}

void Level::replaceBoardObject(BoardObject& oldObject, std::unique_ptr<BoardObject> newObject)
{
	for (int i = 0; i < boardObjects.size(); i++)
	{
		if (boardObjects[i].get() == &oldObject)
		{
			objectsToRemove.push_back(std::move(boardObjects[i]));
			boardObjects.erase(boardObjects.begin() + i);
			this->addBoardObject(std::move(newObject));
			return;
		}
	}
}

const std::vector<std::unique_ptr<BoardObject>>* Level::getBoardObjects() const
{
	return &boardObjects;
}

void Level::cleanUpBoardObjects()
{
	objectsToRemove.clear();
}

void Level::setWidth(int value)
{
	this->width = value;
}

int Level::getWidth() const
{
	return width;
}

void Level::setHeight(int value)
{
	this->height = value;
}

int Level::getHeight() const
{
	return height;
}

bool Level::isAllObjectDoneBehaviour() const
{
	for (int i = 0; i < boardObjects.size(); i++)
	{
		if (!boardObjects.at(i).get()->isDoneAction())
			return false;
	}

	return true;
}

SpaceClaimResponse Level::isSpaceAvailableToMoveOn(Point point, std::string objectKey) const
{
	if (isSpaceOutOfBoards(point))
		return SpaceClaimResponse::DENY;

	for (int i = 0; i < boardObjects.size(); i++)
	{
		if (boardObjects.at(i).get()->getPosition() == point)
		{
			return boardObjects.at(i).get()->canIShareSpaceWithYou(objectKey);
		}
	}

	return SpaceClaimResponse::ALLOW;
}

bool Level::isSpaceOutOfBoards(Point point) const
{
	if (point.getX() < 0)
		return true;

	if (point.getX() >= width)
		return true;

	if (point.getY() < 0)
		return true;

	if (point.getY() >= height)
		return true;

	return false;
}

BoardObject* Level::getObjectAtPoint(Point point) const
{
	if (isSpaceOutOfBoards(point))
		return nullptr;

	for (int i = 0; i < boardObjects.size(); i++)
	{
		if (boardObjects.at(i).get()->getPosition() == point)
			return boardObjects.at(i).get();
	}

	return nullptr;
}


