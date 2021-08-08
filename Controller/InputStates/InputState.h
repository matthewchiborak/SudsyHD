#ifndef INPUT_STATE_H
#define INPUT_STATE_H

#include "../../Model/IGameModel.h"

class InputState
{
public:
	InputState();

	virtual void handle(IGameModel& model, IView& view) = 0;

};

#endif