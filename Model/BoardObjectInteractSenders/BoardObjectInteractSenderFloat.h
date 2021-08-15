#ifndef BOARD_OBJECT_INTERACT_SENDER_FLOAT_H
#define BOARD_OBJECT_INTERACT_SENDER_FLOAT_H

#include "BoardObjectInteractSender.h"

class BoardObjectInteractSenderFloat: public BoardObjectInteractSender
{
public:
	BoardObjectInteractSenderFloat();
	BoardObjectInteractSenderFloat(std::unique_ptr<BoardObjectInteractSender> child);

protected:
	bool senderTemplateMethod(BoardObject& me, Level& level) override;
};

#endif