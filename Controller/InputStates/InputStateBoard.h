#ifndef INPUT_STATE_BOARD_H
#define INPUT_STATE_BOARD_H

#include "InputState.h"

class InputStateBoard: public InputState
{
public:
	InputStateBoard();

	void handle() override;
};

#endif