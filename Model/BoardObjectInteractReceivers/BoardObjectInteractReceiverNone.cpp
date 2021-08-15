#include "BoardObjectInteractReceiverNone.h"

BoardObjectInteractReceiverNone::BoardObjectInteractReceiverNone()
	: BoardObjectInteractReceiver()
{
}

bool BoardObjectInteractReceiverNone::receiverTemplateMethod(std::string key, BoardObject* sender, BoardObject& me, Level& level)
{
	return false;
}
