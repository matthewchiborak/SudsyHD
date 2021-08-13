#include "BoardObjectInteractSenderPush.h"

#include "../BoardObjects/BoardObject.h"

#include "../Level.h"

BoardObjectInteractSenderPush::BoardObjectInteractSenderPush()
	: BoardObjectInteractSender()
{
}

BoardObjectInteractSenderPush::BoardObjectInteractSenderPush(std::unique_ptr<BoardObjectInteractSender> child)
	: BoardObjectInteractSender(std::move(child))
{
}

void BoardObjectInteractSenderPush::senderTemplateMethod(BoardObject& me, Level& level)
{
	//Get the would be receiver if it exists
	BoardObject* receiver = level.getObjectAtPoint(me.getPosition() + me.getLastDirFacing());

	if (receiver == nullptr)
		return;

	receiver->interactReceive("PUSH", &me, level);
}
