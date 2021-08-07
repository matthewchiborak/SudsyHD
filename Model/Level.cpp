#include "Level.h"

#include <iostream>

Level::Level()
{
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
