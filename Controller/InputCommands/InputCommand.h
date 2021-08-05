#ifndef INPUT_COMMAND_H
#define INPUT_COMMAND_H

class InputCommand
{
public:
	InputCommand();

	virtual void execute() = 0;
};

#endif