#include "GameState.h"

GameState::GameState(IGameModel& model, IView& view)
	: model(&model), framesPassed(0), view(&view)
{
}
