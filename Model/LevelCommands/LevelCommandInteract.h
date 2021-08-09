#ifndef LEVEL_COMMAND_INTERACT_H
#define LEVEL_COMMAND_INTERACT_H

#include "LevelCommandMove.h"

class LevelCommandInteract: public LevelCommand
{
public:
	LevelCommandInteract(LevelCommandMove* moveCmd);

	void execute() override;

private:
	LevelCommandMove* moveCmd;
};

#endif