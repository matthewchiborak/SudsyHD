#include "GameContext.h"

#include "GameStateWait.h"

GameContext::GameContext()
	: state(std::make_unique<GameStateWait>())
{
}

void GameContext::request()
{
	state->handle();
}

void GameContext::setState(std::unique_ptr<GameState> state)
{
	this->state = std::move(state);
}
