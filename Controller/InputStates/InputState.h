#ifndef INPUT_STATE_H
#define INPUT_STATE_H

class InputState
{
public:
	InputState();

	virtual void handle() = 0;
};

#endif