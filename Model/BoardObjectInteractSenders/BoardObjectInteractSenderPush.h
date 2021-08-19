#ifndef BOARD_OBJECT_INTERACT_SENDER_PUSH_H
#define BOARD_OBJECT_INTERACT_SENDER_PUSH_H

#include "BoardObjectInteractSender.h"

class BoardObjectInteractSenderPush: public BoardObjectInteractSender
{
public:
	BoardObjectInteractSenderPush();

protected:
	bool senderTemplateMethod(BoardObject& me, Level& level) override;
};

#endif