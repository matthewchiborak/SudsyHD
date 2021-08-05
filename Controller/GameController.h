#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "../Model/IGameModel.h"
#include "../View/IView.h"

class GameController
{
public:
	GameController(
		IGameModel& model,
		IView& view
	);

private:
	IGameModel* model;
	IView* view;

};

#endif