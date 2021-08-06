#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <chrono>

#include "../Model/IGameModel.h"
#include "../View/IView.h"

#include "InputStates/InputContext.h"

class GameController
{
public:
	GameController(
		IGameModel& model,
		IView& view
	);

	void start();

private:
	IGameModel* model;
	IView* view;

	InputContext context;
};

#endif