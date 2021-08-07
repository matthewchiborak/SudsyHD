#include "GameController.h"

GameController::GameController(IGameModel& model, IView& view)
	: IGameController(model, view)
{
}

void GameController::start()
{
	model->loadLevel(1);

	while (view->isWindowOpen())
	{
		model->advance();
		context.request();
		view->draw();
	}

	view->clearMemory();
}

