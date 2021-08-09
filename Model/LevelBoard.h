#ifndef LEVEL_BOARD_H
#define LEVEL_BOARD_H

#include "Level.h"

class LevelBoard: public Level
{
public:
	LevelBoard();
	
	void advance() override;
	void move(const Point direction) override;
	void interact() override;
	void change(bool next) override;

	void setMoveCommand(std::unique_ptr<LevelCommand> cmd);
	void setInteractCommand(std::unique_ptr<LevelCommand> cmd);
	void setChangeNextCommand(std::unique_ptr<LevelCommand> cmd);
	void setChangePrevCommand(std::unique_ptr<LevelCommand> cmd);

private:
	std::unique_ptr<LevelCommand> moveCommand;
	std::unique_ptr<LevelCommand> interactCommand;
	std::unique_ptr<LevelCommand> changeNextCommand;
	std::unique_ptr<LevelCommand> changePrevCommand;
};

#endif