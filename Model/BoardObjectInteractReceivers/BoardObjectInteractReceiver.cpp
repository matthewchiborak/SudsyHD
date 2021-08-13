#include "BoardObjectInteractReceiver.h"

BoardObjectInteractReceiver::BoardObjectInteractReceiver()
	: hasChild(false)
{
}

BoardObjectInteractReceiver::BoardObjectInteractReceiver(std::unique_ptr<BoardObjectInteractReceiver> child)
	: child(std::move(child)), hasChild(true)
{
}

void BoardObjectInteractReceiver::execute(std::string key, BoardObject* sender, BoardObject& me, Level& level)
{
	receiverTemplateMethod(key, sender, me, level);

	if (hasChild)
		child.get()->execute(key, sender, me, level);
}
