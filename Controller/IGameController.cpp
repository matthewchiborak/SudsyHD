#include "IGameController.h"

IGameController::IGameController(IGameModel& model, IView& view)
	: model(&model), view(&view)
{
}
