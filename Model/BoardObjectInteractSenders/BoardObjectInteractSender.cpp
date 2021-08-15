#include "BoardObjectInteractSender.h"

BoardObjectInteractSender::BoardObjectInteractSender()
	: hasChild(false)
{
}

BoardObjectInteractSender::BoardObjectInteractSender(std::unique_ptr<BoardObjectInteractSender> child)
	: child(std::move(child)), hasChild(true)
{
}

bool BoardObjectInteractSender::execute(BoardObject& me, Level& level)
{
	if (!senderTemplateMethod(me, level))
		return false;

	if (hasChild)
		return child.get()->execute(me, level);

	return true;
}
