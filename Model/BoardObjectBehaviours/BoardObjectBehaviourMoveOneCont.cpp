#include "BoardObjectBehaviourMoveOneCont.h"

#include <iostream>

#include "../BoardObjects/BoardObject.h"
#include "../Level.h"

BoardObjectBehaviourMoveOneCont::BoardObjectBehaviourMoveOneCont(Point dir)
	: dir(dir), originalPosSet(false), meOriginalPos(0, 0), hasClaimedSpace(false)
{
}

void BoardObjectBehaviourMoveOneCont::execute(float t, BoardObject& me, Level& level)
{
	if (!originalPosSet)
	{
		meOriginalPos = me.getPosition();
		originalPosSet = true;
	}

	if (actionDone)
		return;

	if (!hasClaimedSpace)
	{
		SpaceClaimResponse claimRes = level.isSpaceAvailableToMoveOn(me.getPosition() + dir, me.getSpaceSharingKey());
		if (SpaceClaimResponse::DENY == claimRes)
		{
			this->dir = Point(dir.getX() * -1, dir.getY() * -1);
			actionDone = true;
			return;
		}
		me.setPosition(me.getPosition() + dir);
		hasClaimedSpace = true;
	}

	float newX = meOriginalPos.getX() + dir.getX() * t;
	float newY = meOriginalPos.getY() + dir.getY() * t;
	me.setPositionF(PointF(newX, newY));
	me.setLastDirFacing(dir);

	if (t >= 1)
	{
		actionDone = true;
	}
}
