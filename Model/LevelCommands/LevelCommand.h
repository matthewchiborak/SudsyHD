#ifndef LEVEL_COMMAND_H
#define LEVEL_COMMAND_H

class LevelCommand
{
public:
	LevelCommand();

	virtual void execute() = 0;
};

#endif