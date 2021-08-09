#ifndef LEVEL_COMMAND_SWITCH_H
#define LEVEL_COMMAND_SWITCH_H

#include "LevelCommandMove.h"

class LevelCommandSwitch: public LevelCommand
{
public:
	LevelCommandSwitch(LevelCommandMove* moveCmd, bool isNext);

	void execute() override;

private:
	bool isNext;
	LevelCommandMove* moveCmd;
};

#endif