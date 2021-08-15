#include "BoardObjectInteractSenderNone.h"

BoardObjectInteractSenderNone::BoardObjectInteractSenderNone()
	: BoardObjectInteractSender()
{
}

bool BoardObjectInteractSenderNone::senderTemplateMethod(BoardObject& me, Level& level)
{
	return true;
}
