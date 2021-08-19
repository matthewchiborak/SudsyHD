#ifndef BOARD_OBJECT_INTERACT_SENDER_FLOAT_H
#define BOARD_OBJECT_INTERACT_SENDER_FLOAT_H

#include "BoardObjectInteractSender.h"

class BoardObjectInteractSenderFloat: public BoardObjectInteractSender
{
public:
	BoardObjectInteractSenderFloat();

protected:
	bool senderTemplateMethod(BoardObject& me, Level& level) override;

	BoardObject* previousReceiver;
};

#endif