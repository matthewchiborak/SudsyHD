#include "GameStateWin.h"

#include <iostream>

GameStateWin::GameStateWin(IGameModel& model)
	: GameState(model)
{
}

void GameStateWin::advance()
{
}

void GameStateWin::move(const Point direction)
{
}

void GameStateWin::interact()
{
	std::cout << "Go to the next level\n";
}

void GameStateWin::change(bool next)
{
}
