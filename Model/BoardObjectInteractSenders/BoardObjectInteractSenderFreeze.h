#ifndef BOARD_OBJECT_INTERACT_SENDER_FREEZE_H
#define BOARD_OBJECT_INTERACT_SENDER_FREEZE_H

#include "BoardObjectInteractSender.h"

class BoardObjectInteractSenderFreeze: public BoardObjectInteractSender
{
public:
	BoardObjectInteractSenderFreeze();

protected:
	bool senderTemplateMethod(BoardObject& me, Level& level) override;
};

#endif