#include "BoardObjectInteractSenderFloat.h"

#include "../BoardObjects/BoardObject.h"
#include "../Level.h"

BoardObjectInteractSenderFloat::BoardObjectInteractSenderFloat()
    : BoardObjectInteractSender()
{
}

BoardObjectInteractSenderFloat::BoardObjectInteractSenderFloat(std::unique_ptr<BoardObjectInteractSender> child)
    : BoardObjectInteractSender(std::move(child))
{
}

bool BoardObjectInteractSenderFloat::senderTemplateMethod(BoardObject& me, Level& level)
{
	BoardObject* receiver = level.getObjectAtPoint(me.getPosition() + me.getLastDirFacing());

	if (receiver == nullptr)
		return false;

	return receiver->interactReceive("FLOAT", &me, level);
}
