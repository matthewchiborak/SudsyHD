#include "BoardObjectInteractReceiverPush.h"

#include "../BoardObjects/BoardObject.h"

#include "../BoardObjectBehaviours/BoardObjectBehaviourMoveInfinite.h"

BoardObjectInteractReceiverPush::BoardObjectInteractReceiverPush()
	: BoardObjectInteractReceiver()
{
}

bool BoardObjectInteractReceiverPush::receiverTemplateMethod(std::string key, BoardObject* sender, BoardObject& me, Level& level)
{
	if (key != "PUSH")
		return false;

	std::unique_ptr<BoardObjectBehaviourMoveInfinite> behave = std::make_unique<BoardObjectBehaviourMoveInfinite>(sender->getPosition() - me.getPosition());

	if (!behave.get()->wouldBeAbleToExecute(me, level))
		return false;

	me.setBehaviour(std::move(behave));

	return true;
}
