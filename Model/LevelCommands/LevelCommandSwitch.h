#ifndef LEVEL_COMMAND_SWITCH_H
#define LEVEL_COMMAND_SWITCH_H

#include "LevelCommand.h"
#include "LevelCommandMove.h"

class LevelCommandSwitch: public LevelCommand
{
public:
	LevelCommandSwitch(LevelCommandMove* moveCmd, bool isNext);

	bool execute() override;
	void draw(IView& view) override;

private:
	bool isNext;
	LevelCommandMove* moveCmd;
};

#endif