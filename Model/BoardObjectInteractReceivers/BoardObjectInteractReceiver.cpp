#include "BoardObjectInteractReceiver.h"

BoardObjectInteractReceiver::BoardObjectInteractReceiver()
	: hasChild(false)
{
}

BoardObjectInteractReceiver::BoardObjectInteractReceiver(std::unique_ptr<BoardObjectInteractReceiver> child)
	: child(std::move(child)), hasChild(true)
{
}

bool BoardObjectInteractReceiver::execute(std::string key, BoardObject* sender, BoardObject& me, Level& level)
{
	if (!receiverTemplateMethod(key, sender, me, level))
		return false;

	if (hasChild)
		return child.get()->execute(key, sender, me, level);

	return true;
}
