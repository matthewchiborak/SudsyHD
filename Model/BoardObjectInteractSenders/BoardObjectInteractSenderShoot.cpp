#include "BoardObjectInteractSenderShoot.h"

#include "../BoardObjects/BoardObjectArrow.h"
#include "../BoardObjectBehaviours/BoardObjectBehaviourMoveInfinite.h"
#include "../BoardObjectInteractSenders/BoardObjectInteractSenderNone.h"
#include "../BoardObjectInteractReceivers/BoardObjectInteractReceiverNone.h"

#include "../Level.h"

BoardObjectInteractSenderShoot::BoardObjectInteractSenderShoot()
	: BoardObjectInteractSender()
{
}

bool BoardObjectInteractSenderShoot::senderTemplateMethod(BoardObject& me, Level& level)
{
	Point potentialPoint = me.getPosition() + me.getLastDirFacing();

	BoardObject* receiver = level.getObjectAtPoint(potentialPoint);

	if (receiver != nullptr)
		return false;

	if (level.isSpaceOutOfBoards(potentialPoint))
		return false;

	std::unique_ptr<BoardObject> newObject = std::make_unique<BoardObjectArrow>(
		potentialPoint,
		"Arrow",
		std::move(std::make_unique<BoardObjectBehaviourMoveInfinite>(me.getLastDirFacing())),
		std::move(std::make_unique<BoardObjectInteractSenderNone>()),
		std::move(std::make_unique<BoardObjectInteractReceiverNone>())
		);
	level.addBoardObject(std::move(newObject));

	return true;
}
