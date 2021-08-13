#ifndef BOARD_OBJECT_INTERACT_SENDER_NONE_H
#define BOARD_OBJECT_INTERACT_SENDER_NONE_H

#include "BoardObjectInteractSender.h"

class BoardObjectInteractSenderNone: public BoardObjectInteractSender
{
public:
	BoardObjectInteractSenderNone();

protected:
	void senderTemplateMethod(BoardObject& me, Level& level) override;
};

#endif