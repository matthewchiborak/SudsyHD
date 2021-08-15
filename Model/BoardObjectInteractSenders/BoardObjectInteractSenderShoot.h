#ifndef BOARD_OBJECT_INTERACT_SENDER_SHOOT_H
#define BOARD_OBJECT_INTERACT_SENDER_SHOOT_H

#include "BoardObjectInteractSender.h"

class BoardObjectInteractSenderShoot: public BoardObjectInteractSender
{
public:
	BoardObjectInteractSenderShoot();
	BoardObjectInteractSenderShoot(std::unique_ptr<BoardObjectInteractSender> child);

protected:
	bool senderTemplateMethod(BoardObject& me, Level& level) override;
};

#endif