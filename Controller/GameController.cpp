#include "GameController.h"

GameController::GameController(IGameModel& model, IView& view)
	: model(&model), view(&view)
{
}

void GameController::start()
{
	while (view->isWindowOpen())
	{
		model->advance();
		context.request();
		view->draw();
	}

	view->clearMemory();
}

