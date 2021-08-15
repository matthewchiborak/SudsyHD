#include "BoardObjectInteractReceiverFloat.h"

#include "../BoardObjects/BoardObject.h"

BoardObjectInteractReceiverFloat::BoardObjectInteractReceiverFloat()
	: BoardObjectInteractReceiver()
{
}

BoardObjectInteractReceiverFloat::BoardObjectInteractReceiverFloat(std::unique_ptr<BoardObjectInteractReceiver> child)
	: BoardObjectInteractReceiver(std::move(child))
{
}

bool BoardObjectInteractReceiverFloat::receiverTemplateMethod(std::string key, BoardObject* sender, BoardObject& me, Level& level)
{
	if (key != "FLOAT")
		return false;

	me.setSpaceSharingKey("Rock-Float");

	return true;
}
