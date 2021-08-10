#include "BoardObjectBehaviour.h"

BoardObjectBehaviour::BoardObjectBehaviour()
	: actionDone(false)
{
}

bool BoardObjectBehaviour::isDone()
{
	return actionDone;
}
