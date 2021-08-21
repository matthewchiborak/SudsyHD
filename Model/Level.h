#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <memory>

#include "BoardObjects/BoardObject.h"
#include "LevelCommands/LevelCommand.h"

#include "SpaceClaimResponses.h"

class Level
{
public:
	Level();
	~Level();

	virtual void advance(float t) = 0;
	virtual void handleCollisions() = 0;
	virtual bool move(const Point direction) = 0;
	virtual bool interact() = 0;
	virtual void change(bool next) = 0;
	virtual void drawCommands(IView& view) const = 0;
	
	void addBoardObject(std::unique_ptr<BoardObject> object);
	void replaceBoardObject(BoardObject& oldObject, std::unique_ptr<BoardObject> newObject);
	const std::vector<std::unique_ptr<BoardObject>>* getBoardObjects() const;

	void cleanUpBoardObjects();

	void setWidth(int value);
	int getWidth() const;
	void setHeight(int value);
	int getHeight() const;

	bool isAllObjectDoneBehaviour() const;
	SpaceClaimResponse isSpaceAvailableToMoveOn(Point point, std::string objectKey) const;
	bool isSpaceOutOfBoards(Point point) const;
	BoardObject* getObjectAtPoint(Point point) const;
	virtual bool isAtLeastOneOfObjectTypeAlive(std::string key) const = 0;

protected:
	int width;
	int height;

	std::vector<std::unique_ptr<BoardObject>> boardObjects;
	std::vector<std::unique_ptr<BoardObject>> objectsToRemove;
};

#endif