#include "BoardObjectBehaviourNone.h"

#include "../BoardObjects/BoardObject.h"
#include "../IGameModel.h"

BoardObjectBehaviourNone::BoardObjectBehaviourNone()
	: BoardObjectBehaviour()
{
}

void BoardObjectBehaviourNone::execute(float t, BoardObject& me, IGameModel& model)
{
	actionDone = true;
}
