#include "GameStateGameOver.h"

#include <iostream>

GameStateGameOver::GameStateGameOver(IGameModel& model)
	: GameState(model)
{
}

void GameStateGameOver::advance()
{
}

void GameStateGameOver::move(const Point direction)
{
}

void GameStateGameOver::interact()
{
	//Reload the level
	std::cout << "Time to reload\n";
}

void GameStateGameOver::change(bool next)
{
}
