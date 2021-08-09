#include "LevelCommandMove.h"

#include <iostream>

LevelCommandMove::LevelCommandMove()
	: LevelCommand(), currentPlayer(0)
{
}

void LevelCommandMove::execute()
{
	std::cout << "56 Level Move Command Execute called\n";
}

void LevelCommandMove::addPlayer(BoardObject& object)
{
	this->players.push_back(&object);
}

void LevelCommandMove::switchPlayer(bool next)
{
	std::cout << "ghfdjkshdklfg Level Move Command Switch Player Called\n";

	if (players.size() <= 1)
		return;

	if (next)
	{
		currentPlayer++;

		if (currentPlayer >= players.size())
			currentPlayer = 0;
		return;
	}

	currentPlayer--;

	if (currentPlayer < 0)
		currentPlayer = players.size() - 1;
}

BoardObject* LevelCommandMove::getCurrentPlayer()
{
	return players[currentPlayer];
}
