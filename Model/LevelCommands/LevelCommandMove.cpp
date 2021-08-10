#include "LevelCommandMove.h"

#include <iostream>

#include "../BoardObjectBehaviours/BoardObjectBehaviourMoveOne.h"

LevelCommandMove::LevelCommandMove()
	: LevelCommandPoint(), currentPlayer(0)
{
}

void LevelCommandMove::execute(Point point)
{
	this->players[currentPlayer]->setBehaviour(std::move(std::make_unique<BoardObjectBehaviourMoveOne>(point)));
}

void LevelCommandMove::addPlayer(BoardObject& object)
{
	this->players.push_back(&object);
}

void LevelCommandMove::switchPlayer(bool next)
{
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
