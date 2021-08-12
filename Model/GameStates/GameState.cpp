#include "GameState.h"

GameState::GameState(IGameModel& model)
	: model(&model), timeStateBegan(std::chrono::steady_clock::now())
{
}
