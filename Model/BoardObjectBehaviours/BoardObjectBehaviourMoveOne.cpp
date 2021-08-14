#include "BoardObjectBehaviourMoveOne.h"

#include <iostream>

#include "BoardObjectBehaviourNone.h"

#include "../BoardObjects/BoardObject.h"
#include "../Level.h"

BoardObjectBehaviourMoveOne::BoardObjectBehaviourMoveOne(Point dir, float t)
	: dir(dir), startingT(t), originalPosSet(false), meOriginalPos(0, 0), hasClaimedSpace(false)
{
}

void BoardObjectBehaviourMoveOne::execute(float t, BoardObject& me, Level& level)
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
		me.setPosition(me.getPosition() + dir);
		hasClaimedSpace = true;
	}

	t -= startingT;

	float newX = meOriginalPos.getX() + dir.getX() * t;
	float newY = meOriginalPos.getY() + dir.getY() * t;
	me.setPositionF(PointF(newX, newY));
	me.setLastDirFacing(dir);

	if (t >= 1)
	{
		me.setBehaviour(std::move(std::make_unique<BoardObjectBehaviourNone>()));
		actionDone = true;
	}
}
