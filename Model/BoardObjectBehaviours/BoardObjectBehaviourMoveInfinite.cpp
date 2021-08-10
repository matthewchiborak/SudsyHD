#include "BoardObjectBehaviourMoveInfinite.h"

#include <iostream>

#include "BoardObjectBehaviourNone.h"

#include "../BoardObjects/BoardObject.h"
#include "../IGameModel.h"

BoardObjectBehaviourMoveInfinite::BoardObjectBehaviourMoveInfinite(Point dir)
	: dir(dir)
{
}

void BoardObjectBehaviourMoveInfinite::execute(float t, BoardObject& me, IGameModel& model)
{
	std::cout << "TODO ACTUALLY HAVE THE GAME OBJECT MOVE\n";

	//If a whole t has passed and the object has been forced not to move by something else in the program....
	// or. I have access to the model. So i can just check if theres someting in the next space.............
	//if(can move forward)
	if (t >= 10)
	{
		me.setBehaviour(std::move(std::make_unique<BoardObjectBehaviourNone>()));
		actionDone = true;
	}
}
