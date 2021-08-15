#include "BoardObjectInteractSenderFreeze.h"

#include "../BoardObjects/BoardObject.h"
#include "../Level.h"

BoardObjectInteractSenderFreeze::BoardObjectInteractSenderFreeze()
	: BoardObjectInteractSender()
{
}

BoardObjectInteractSenderFreeze::BoardObjectInteractSenderFreeze(std::unique_ptr<BoardObjectInteractSender> child)
	: BoardObjectInteractSender(std::move(child))
{
}

bool BoardObjectInteractSenderFreeze::senderTemplateMethod(BoardObject& me, Level& level)
{
	//Get the would be receiver if it exists
	BoardObject* receiver = level.getObjectAtPoint(me.getPosition() + me.getLastDirFacing());

	if (receiver == nullptr)
		return false;

	return receiver->interactReceive("FREEZE", &me, level);
}
