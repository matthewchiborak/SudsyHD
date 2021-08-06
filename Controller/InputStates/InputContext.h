#ifndef INPUT_CONTEXT_H
#define INPUT_CONTEXT_H

#include "InputState.h"

class InputContext
{
public:
	InputContext();

	void request();

private:
	InputState* state;
};

#endif