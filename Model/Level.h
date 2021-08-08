#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <memory>

#include "BoardObjects/BoardObject.h"

class Level
{
public:
	Level();
	~Level();

	//virtual void move(const Point direction) = 0;
	//virtual void interact() = 0;
	
	void addBoardObject(std::unique_ptr<BoardObject> object);
	const std::vector<std::unique_ptr<BoardObject>>* getBoardObjects() const;

	void setWidth(int value);
	int getWidth() const;
	void setHeight(int value);
	int getHeight() const;

protected:
	int width;
	int height;

	std::vector<std::unique_ptr<BoardObject>> boardObjects;
};

#endif