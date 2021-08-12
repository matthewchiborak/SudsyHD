#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <memory>

#include "BoardObjects/BoardObject.h"
#include "LevelCommands/LevelCommand.h"

class Level
{
public:
	Level();
	~Level();

	virtual void advance(float t) = 0;
	virtual void move(const Point direction) = 0;
	virtual void interact() = 0;
	virtual void change(bool next) = 0;
	
	void addBoardObject(std::unique_ptr<BoardObject> object);
	const std::vector<std::unique_ptr<BoardObject>>* getBoardObjects() const;

	void setWidth(int value);
	int getWidth() const;
	void setHeight(int value);
	int getHeight() const;

	bool isAllObjectDoneBehaviour() const;
	bool isSpaceAvailableToMoveOn(Point point) const;
	bool isSpaceOutOfBoards(Point point) const;

protected:
	int width;
	int height;

	std::vector<std::unique_ptr<BoardObject>> boardObjects;

};

#endif