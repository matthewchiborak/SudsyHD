#ifndef I_GAME_CONTROLLER_H
#define I_GAME_CONTROLLER_H

#include <chrono>

#include "../Model/IGameModel.h"
#include "../View/IView.h"

#include "InputStates/InputContext.h"

class IGameController
{
public:
	IGameController(
		IGameModel& model,
		IView& view
	);

	virtual void start() = 0;

protected:
	IGameModel* model;
	IView* view;

	InputContext context;
};

#endif