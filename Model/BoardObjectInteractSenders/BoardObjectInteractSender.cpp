#include "BoardObjectInteractSender.h"

BoardObjectInteractSender::BoardObjectInteractSender()
	: hasChild(false)
{
}

bool BoardObjectInteractSender::execute(BoardObject& me, Level& level)
{
	if (senderTemplateMethod(me, level))
		return true;

	if (hasChild)
		return child.get()->execute(me, level);

	return false;
}

void BoardObjectInteractSender::addChild(std::unique_ptr<BoardObjectInteractSender> child)
{
	if (hasChild)
	{
		this->child.get()->addChild(std::move(child));
		return;
	}

	this->child = std::move(child);
	hasChild = true;
}
