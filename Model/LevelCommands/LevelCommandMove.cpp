#include "LevelCommandMove.h"

#include <iostream>

#include "../BoardObjectBehaviours/BoardObjectBehaviourMoveOne.h"

LevelCommandMove::LevelCommandMove(Level& level)
	: LevelCommandPoint(), currentPlayer(0), level(&level)
{
}

bool LevelCommandMove::execute(Point point)
{
	//No matter what, want they to change directions
	this->players[currentPlayer]->setLastDirFacing(point);

	//Check if player can move
	std::unique_ptr<BoardObjectBehaviourMoveOne> behave = std::make_unique<BoardObjectBehaviourMoveOne>(point);

	if(!behave.get()->wouldBeAbleToExecute(*(this->players[currentPlayer]), *level))
		return false; 

	this->players[currentPlayer]->setBehaviour(std::move(behave));

	return true;
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
