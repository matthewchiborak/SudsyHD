#include "InputContext.h"

#include "InputStateBoard.h"

InputContext::InputContext()
	: state(new InputStateBoard())
{
}

void InputContext::request()
{
	state->handle();
}
