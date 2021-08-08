#include "Level.h"

#include <iostream>

Level::Level()
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
