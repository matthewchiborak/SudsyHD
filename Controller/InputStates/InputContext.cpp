#include "InputContext.h"

#include "InputStateBoard.h"

InputContext::InputContext()
	: state(std::make_unique<InputStateBoard>())
{
}

void InputContext::request()
{
	state->handle();
}

void InputContext::setState(std::unique_ptr<InputState> state)
{
	this->state = std::move(state);
}
