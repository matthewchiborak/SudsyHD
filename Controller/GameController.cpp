#include "GameController.h"

GameController::GameController(IGameModel& model, IView& view)
	: IGameController(model, view)
{
}

void GameController::start()
{
	model->loadLevel(1);

	bool loadedOnce = false;

	while (view->isWindowOpen())
	{
		handleUserInput();
		model->advance();
		view->draw();
	}

	view->clearMemory();
}

void GameController::handleUserInput()
{
	context.request(*(this->model), *(this->view));
}

