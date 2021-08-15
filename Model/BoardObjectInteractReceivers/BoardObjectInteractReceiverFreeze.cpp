#include "BoardObjectInteractReceiverFreeze.h"

#include "../BoardObjects/BoardObjectRock.h"
#include "../Level.h"
#include "../BoardObjectBehaviours/BoardObjectBehaviourNone.h"
#include "../BoardObjectInteractSenders/BoardObjectInteractSenderNone.h"
#include "BoardObjectInteractReceiverNone.h"

BoardObjectInteractReceiverFreeze::BoardObjectInteractReceiverFreeze()
	: BoardObjectInteractReceiver()
{
}

BoardObjectInteractReceiverFreeze::BoardObjectInteractReceiverFreeze(std::unique_ptr<BoardObjectInteractReceiver> child)
	: BoardObjectInteractReceiver(std::move(child))
{
}

bool BoardObjectInteractReceiverFreeze::receiverTemplateMethod(std::string key, BoardObject* sender, BoardObject& me, Level& level)
{
	if (key != "FREEZE")
		return false;

	std::unique_ptr<BoardObjectRock> newObj = std::make_unique<BoardObjectRock>(
		me.getPosition(),
		me.getSpriteKey() + "-Frozen",
		std::move(std::make_unique<BoardObjectBehaviourNone>()),
		std::move(std::make_unique<BoardObjectInteractSenderNone>()),
		std::move(std::make_unique<BoardObjectInteractReceiverNone>())
		);

	level.replaceBoardObject(me, std::move(newObj));

	return true;
}
