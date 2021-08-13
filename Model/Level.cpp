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

const std::vector<std::unique_ptr<BoardObject>>* Level::getBoardObjects() const
{
	return &boardObjects;
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

bool Level::isSpaceAvailableToMoveOn(Point point) const
{
	if (isSpaceOutOfBoards(point))
		return false;

	for (int i = 0; i < boardObjects.size(); i++)
	{
		if (boardObjects.at(i).get()->getPosition() == point)
			return false;
	}

	return true;
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
