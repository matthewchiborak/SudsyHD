#include "GameState.h"

GameState::GameState(IGameModel& model)
	: model(&model), framesPassed(0)
{
}
