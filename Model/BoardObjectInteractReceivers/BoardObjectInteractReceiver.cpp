#include "BoardObjectInteractReceiver.h"

BoardObjectInteractReceiver::BoardObjectInteractReceiver()
	: hasChild(false)
{
}

bool BoardObjectInteractReceiver::execute(std::string key, BoardObject* sender, BoardObject& me, Level& level)
{
	if (receiverTemplateMethod(key, sender, me, level))
		return true;

	if (hasChild)
		return child.get()->execute(key, sender, me, level);

	return false;
}

void BoardObjectInteractReceiver::addChild(std::unique_ptr<BoardObjectInteractReceiver> child)
{
	if (hasChild)
	{
		this->child.get()->addChild(std::move(child));
		return;
	}

	this->child = std::move(child);
	hasChild = true;
}
