#include "BoardObjectInteractSenderFloat.h"

#include "../BoardObjects/BoardObject.h"
#include "../Level.h"

BoardObjectInteractSenderFloat::BoardObjectInteractSenderFloat()
    : BoardObjectInteractSender(), previousReceiver(nullptr)
{
}

bool BoardObjectInteractSenderFloat::senderTemplateMethod(BoardObject& me, Level& level)
{
	BoardObject* receiver = level.getObjectAtPoint(me.getPosition() + me.getLastDirFacing());

	if (receiver == nullptr)
		return false;

	bool receiverResult = receiver->interactReceive("FLOAT", &me, level);
	if (receiverResult)
	{
		if (previousReceiver != nullptr)
		{
			previousReceiver->resetSpaceSharingKey();
			previousReceiver->resetSpriteKey();
		}

		previousReceiver = receiver;
	}
	
	return receiverResult;
}
