#include "BoardObjectInteractReceiverNone.h"

BoardObjectInteractReceiverNone::BoardObjectInteractReceiverNone()
	: BoardObjectInteractReceiver()
{
}

void BoardObjectInteractReceiverNone::receiverTemplateMethod(std::string key, BoardObject* sender, BoardObject& me, Level& level)
{
}
