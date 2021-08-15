#include "BoardObjectBehaviourNone.h"

#include "../BoardObjects/BoardObject.h"
#include "../Level.h"

BoardObjectBehaviourNone::BoardObjectBehaviourNone()
	: BoardObjectBehaviour()
{
}

void BoardObjectBehaviourNone::execute(float t, BoardObject& me, Level& level)
{
	actionDone = true;
}

bool BoardObjectBehaviourNone::wouldBeAbleToExecute(BoardObject& me, Level& level)
{
	return false;
}
