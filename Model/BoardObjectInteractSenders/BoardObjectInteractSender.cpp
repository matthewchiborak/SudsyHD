#include "BoardObjectInteractSender.h"

BoardObjectInteractSender::BoardObjectInteractSender()
	: hasChild(false)
{
}

BoardObjectInteractSender::BoardObjectInteractSender(std::unique_ptr<BoardObjectInteractSender> child)
	: child(std::move(child)), hasChild(true)
{
}

void BoardObjectInteractSender::execute(BoardObject& me, Level& level)
{
	senderTemplateMethod(me, level);

	if (hasChild)
		child.get()->execute(me, level);
}
