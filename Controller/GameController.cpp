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

