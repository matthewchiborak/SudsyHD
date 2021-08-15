#include "BoardObjectBehaviourMoveOneCont.h"

#include <iostream>

#include "../BoardObjects/BoardObject.h"
#include "../Level.h"

BoardObjectBehaviourMoveOneCont::BoardObjectBehaviourMoveOneCont(Point dir)
	: dir(dir), originalPosSet(false), meOriginalPos(0, 0), hasClaimedSpace(false), lastT(0)
{
}

void BoardObjectBehaviourMoveOneCont::execute(float t, BoardObject& me, Level& level)
{
	if (t < lastT)
		reset();

	if (!originalPosSet)
	{
		meOriginalPos = me.getPosition();
		originalPosSet = true;
	}

	if (actionDone)
		return;

	lastT = t;

	if (!hasClaimedSpace)
	{
		SpaceClaimResponse claimRes = level.isSpaceAvailableToMoveOn(me.getPosition() + dir, me.getSpaceSharingKey());
		if (SpaceClaimResponse::DENY == claimRes)
		{
			this->dir = Point(dir.getX() * -1, dir.getY() * -1);
			actionDone = true;
			lastT = 1;
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

bool BoardObjectBehaviourMoveOneCont::wouldBeAbleToExecute(BoardObject& me, Level& level)
{
	SpaceClaimResponse claimRes = level.isSpaceAvailableToMoveOn(me.getPosition() + dir, me.getSpaceSharingKey());
	if (SpaceClaimResponse::DENY == claimRes)
	{
		return false;
	}

	return true;
}

void BoardObjectBehaviourMoveOneCont::reset()
{
	originalPosSet = false;
	meOriginalPos = Point(0, 0); 
	hasClaimedSpace = false; 
	lastT = 0;
	actionDone = false;
}
