#include "GameContext.h"

#include "GameStateWait.h"

GameContext::GameContext()
	: state(new GameStateWait())
{
}

void GameContext::request()
{
	state->handle();
}
