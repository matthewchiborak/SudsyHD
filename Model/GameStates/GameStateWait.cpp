#include "GameStateWait.h"

#include <iostream>

GameStateWait::GameStateWait()
	: GameState()
{
}

void GameStateWait::advance()
{
	
}

void GameStateWait::move(const Point direction)
{
	std::cout << direction << " : Movve called\n";
}

void GameStateWait::interact()
{
}
