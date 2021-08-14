#include "BoardObjectBehaviourMoveOne.h"

#include <iostream>

#include "BoardObjectBehaviourNone.h"

#include "../BoardObjects/BoardObject.h"
#include "../Level.h"

BoardObjectBehaviourMoveOne::BoardObjectBehaviourMoveOne(Point dir, float t)
	: dir(dir), startingT(t)
{
}

void BoardObjectBehaviourMoveOne::execute(float t, BoardObject& me, Level& level)
{
	if (actionDone)
		return;

	SpaceClaimResponse claimRes = level.isSpaceAvailableToMoveOn(me.getPosition() + dir, me.getSpaceSharingKey());
	if (SpaceClaimResponse::DENY == claimRes)
	{
		me.setBehaviour(std::move(std::make_unique<BoardObjectBehaviourNone>()));
		actionDone = true;
		return;
	}

	t -= startingT;

	float newX = me.getPosition().getX() + dir.getX() * t;
	float newY = me.getPosition().getY() + dir.getY() * t;
	me.setPositionF(PointF(newX, newY));
	me.setLastDirFacing(dir);

	if (t >= 1)
	{
		me.setPosition(me.getPosition() + dir);
		me.setBehaviour(std::move(std::make_unique<BoardObjectBehaviourNone>()));
		actionDone = true;
	}
}
