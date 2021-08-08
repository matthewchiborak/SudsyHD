#include "GameContext.h"

#include "GameStateWait.h"

GameContext::GameContext()
	: state(std::make_unique<GameStateWait>())
{
}

void GameContext::advance()
{
	this->state.get()->advance();
}

void GameContext::move(const Point direction)
{
	this->state.get()->move(direction);
}

void GameContext::interact()
{
	this->state.get()->interact();
}

void GameContext::setState(std::unique_ptr<GameState> state)
{
	this->state = std::move(state);
}
