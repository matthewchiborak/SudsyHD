#include "GameController.h"

GameController::GameController(IGameModel& model, IView& view)
	: model(&model), view(&view)
{
}

