#include "BoardObjectBehaviourMoveInfinite.h"

#include <iostream>

#include "BoardObjectBehaviourNone.h"

#include "../BoardObjects/BoardObject.h"
#include "../Level.h"

#include "BoardObjectBehaviourMoveOne.h"

BoardObjectBehaviourMoveInfinite::BoardObjectBehaviourMoveInfinite(Point dir)
	: dir(dir), lastT(0), originalPosSet(false), meOriginalPos(0,0), hasClaimedSpace(false)
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

	if (!hasClaimedSpace)
	{
		SpaceClaimResponse claimRes = level.isSpaceAvailableToMoveOn(me.getPosition() + dir, me.getSpaceSharingKey());
		if (SpaceClaimResponse::DENY == claimRes)
		{
			me.setBehaviour(std::move(std::make_unique<BoardObjectBehaviourNone>()));
			actionDone = true;
			return;
		}
		if (SpaceClaimResponse::STOP == claimRes)
		{
			me.setBehaviour(std::move(std::make_unique<BoardObjectBehaviourMoveOne>(dir, t)));
			return;
		}
		me.setPosition(me.getPosition() + dir);
		hasClaimedSpace = true;
	}

	float newX = meOriginalPos.getX() + dir.getX() * t;
	float newY = meOriginalPos.getY() + dir.getY() * t;
	me.setPositionF(PointF(newX, newY));
	me.setLastDirFacing(dir);

	if ((int)t > lastT)
	{
		lastT = t;
		hasClaimedSpace = false;
	}
}
