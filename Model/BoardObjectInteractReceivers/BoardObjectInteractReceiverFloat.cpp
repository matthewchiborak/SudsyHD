#include "BoardObjectInteractReceiverFloat.h"

#include "../BoardObjects/BoardObject.h"

BoardObjectInteractReceiverFloat::BoardObjectInteractReceiverFloat()
	: BoardObjectInteractReceiver()
{
}

bool BoardObjectInteractReceiverFloat::receiverTemplateMethod(std::string key, BoardObject* sender, BoardObject& me, Level& level)
{
	if (key != "FLOAT")
		return false;

	me.setSpaceSharingKey("Rock-Float");

	return true;
}
