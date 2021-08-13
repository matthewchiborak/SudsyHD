#include "BoardObjectBehaviourMoveInfinite.h"

#include <iostream>

#include "BoardObjectBehaviourNone.h"

#include "../BoardObjects/BoardObject.h"
#include "../Level.h"

BoardObjectBehaviourMoveInfinite::BoardObjectBehaviourMoveInfinite(Point dir)
	: dir(dir), lastT(0), originalPosSet(false), meOriginalPos(0,0)
{
}

void BoardObjectBehaviourMoveInfinite::execute(float t, BoardObject& me, Level& level)
{
	if (!originalPosSet)
	{
		meOriginalPos = me.getPosition();
		originalPosSet = true;
	}

	if (actionDone)
		return;

	if (!level.isSpaceAvailableToMoveOn(me.getPosition() + dir))
	{
		me.setBehaviour(std::move(std::make_unique<BoardObjectBehaviourNone>()));
		actionDone = true;
		return;
	}

	float newX = meOriginalPos.getX() + dir.getX() * t;
	float newY = meOriginalPos.getY() + dir.getY() * t;
	me.setPositionF(PointF(newX, newY));
	me.setLastDirFacing(dir);

	if ((int)t > lastT)
	{
		lastT = t;
		me.setPosition(me.getPosition() + dir);
	}
}
