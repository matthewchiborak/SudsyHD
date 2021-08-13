#include "BoardObjectInteractReceiverPush.h"

#include "../BoardObjects/BoardObject.h"

#include "../BoardObjectBehaviours/BoardObjectBehaviourMoveInfinite.h"

BoardObjectInteractReceiverPush::BoardObjectInteractReceiverPush()
	: BoardObjectInteractReceiver()
{
}

BoardObjectInteractReceiverPush::BoardObjectInteractReceiverPush(std::unique_ptr<BoardObjectInteractReceiver> child)
	: BoardObjectInteractReceiver(std::move(child))
{
}

void BoardObjectInteractReceiverPush::receiverTemplateMethod(std::string key, BoardObject* sender, BoardObject& me, Level& level)
{
	if (key != "PUSH")
		return;

	me.setBehaviour(std::move(std::make_unique< BoardObjectBehaviourMoveInfinite>(sender->getPosition() - me.getPosition())));
}
