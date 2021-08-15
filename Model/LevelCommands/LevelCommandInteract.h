#ifndef LEVEL_COMMAND_INTERACT_H
#define LEVEL_COMMAND_INTERACT_H

#include "LevelCommand.h"
#include "LevelCommandMove.h"

class LevelCommandInteract: public LevelCommand
{
public:
	LevelCommandInteract(LevelCommandMove* moveCmd, Level& level);

	bool execute() override;

private:
	Level* level;
	LevelCommandMove* moveCmd;
};

#endif