#include "BoardObjectBehaviourMoveOne.h"

#include <iostream>

#include "BoardObjectBehaviourNone.h"

#include "../BoardObjects/BoardObject.h"
#include "../Level.h"

BoardObjectBehaviourMoveOne::BoardObjectBehaviourMoveOne(Point dir)
	: dir(dir)
{
}

void BoardObjectBehaviourMoveOne::execute(float t, BoardObject& me, Level& level)
{
	float newX = me.getPosition().getX() + dir.getX() * t;
	float newY = me.getPosition().getY() + dir.getY() * t;
	me.setPositionF(PointF(newX, newY));

	if (t >= 1)
	{
		me.setPosition(me.getPosition() + dir);
		me.setBehaviour(std::move(std::make_unique<BoardObjectBehaviourNone>()));
		actionDone = true;
	}
}
