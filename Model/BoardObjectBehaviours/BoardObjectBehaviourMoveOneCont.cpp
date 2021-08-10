#include "BoardObjectBehaviourMoveOneCont.h"

#include <iostream>

#include "../BoardObjects/BoardObject.h"
#include "../IGameModel.h"

BoardObjectBehaviourMoveOneCont::BoardObjectBehaviourMoveOneCont(Point dir)
	: dir(dir)
{
}

void BoardObjectBehaviourMoveOneCont::execute(float t, BoardObject& me, IGameModel& model)
{
	std::cout << "TODO ACTUALLY HAVE THE GAME OBJECT MOVE\n";

	if (t >= 1)
	{
		actionDone = true;
	}
}
