#ifndef LEVEL_BOARD_H
#define LEVEL_BOARD_H

#include "Level.h"
#include "LevelCommands/LevelCommandPoint.h"

class LevelBoard: public Level
{
public:
	LevelBoard();
	
	void advance(float t) override;
	bool move(const Point direction) override;
	bool interact() override;
	void change(bool next) override;
	void handleCollisions() override;
	void drawCommands(IView& view) const override;

	bool isAtLeastOneOfObjectTypeAlive(std::string key) const override;

	void setMoveCommand(std::unique_ptr<LevelCommandPoint> cmd);
	void setInteractCommand(std::unique_ptr<LevelCommand> cmd);
	void setChangeNextCommand(std::unique_ptr<LevelCommand> cmd);
	void setChangePrevCommand(std::unique_ptr<LevelCommand> cmd);

private:
	std::unique_ptr<LevelCommandPoint> moveCommand;
	std::unique_ptr<LevelCommand> interactCommand;
	std::unique_ptr<LevelCommand> changeNextCommand;
	std::unique_ptr<LevelCommand> changePrevCommand;

	void removeOrKeepObjectsOnSameSpace(int& i, int& j);
	void handlePeopleCollisions(int& i, int& j);
	void handleEnemyCollisions(int& i, int& j);
	void handleRockCollisions(int& i, int& j);
	void handleRockFloatCollisions(int& i, int& j);
	void handleArrowCollisions(int& i, int& j);
	void handleHoleCollisions(int& i, int& j);
	void handleGoalCollisions(int& i, int& j);

	void resetIndices(int& i, int& j);
};

#endif