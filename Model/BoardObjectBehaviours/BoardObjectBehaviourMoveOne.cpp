#include "BoardObjectBehaviourMoveOne.h"

#include <iostream>

#include "BoardObjectBehaviourNone.h"

#include "../BoardObjects/BoardObject.h"
#include "../IGameModel.h"

BoardObjectBehaviourMoveOne::BoardObjectBehaviourMoveOne(Point dir)
	: dir(dir)
{
}

void BoardObjectBehaviourMoveOne::execute(float t, BoardObject& me, IGameModel& model)
{
	std::cout << "This is Move One:  TODO ACTUALLY HAVE THE GAME OBJECT MOVE" << dir << "\n";

	if (t >= 1)
	{
		me.setBehaviour(std::move(std::make_unique<BoardObjectBehaviourNone>()));
		actionDone = true;
	}
}
