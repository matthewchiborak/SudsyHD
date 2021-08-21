#ifndef INPUT_STATE_BOARD_H
#define INPUT_STATE_BOARD_H

#include "InputState.h"

class InputStateBoard: public InputState
{
public:
	InputStateBoard();

	void handle(IGameModel& model, IView& view) override;

private:
	bool buttonDown;
	bool isPaused;
};

#endif