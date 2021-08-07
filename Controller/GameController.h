#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "IGameController.h"

class GameController: public IGameController
{
public:
	GameController(
		IGameModel& model,
		IView& view
	);

	void start() override;

};

#endif