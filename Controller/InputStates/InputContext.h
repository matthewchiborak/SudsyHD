#ifndef INPUT_CONTEXT_H
#define INPUT_CONTEXT_H

#include <memory>

#include "InputState.h"

class InputContext
{
public:
	InputContext();

	void request();

	void setState(std::unique_ptr<InputState> state);

private:
	std::unique_ptr<InputState> state;
};

#endif