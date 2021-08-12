#include "BoardObjectBehaviourMoveOneCont.h"

#include <iostream>

#include "../BoardObjects/BoardObject.h"
#include "../Level.h"

BoardObjectBehaviourMoveOneCont::BoardObjectBehaviourMoveOneCont(Point dir)
	: dir(dir)
{
}

void BoardObjectBehaviourMoveOneCont::execute(float t, BoardObject& me, Level& level)
{
	if (actionDone)
		return;

	if (!level.isSpaceAvailableToMoveOn(me.getPosition() + dir))
	{
		this->dir = Point(dir.getX() * -1, dir.getY() * -1);
		actionDone = true;
		return;
	}

	float newX = me.getPosition().getX() + dir.getX() * t;
	float newY = me.getPosition().getY() + dir.getY() * t;
	me.setPositionF(PointF(newX, newY));

	if (t >= 1)
	{
		me.setPosition(me.getPosition() + dir);
		actionDone = true;
	}
}
