#ifndef LEVEL_COMMAND_H
#define LEVEL_COMMAND_H

class IView;

class LevelCommand
{
public:
	LevelCommand();

	virtual bool execute() = 0;
	virtual void draw(IView& view) = 0;
};

#endif