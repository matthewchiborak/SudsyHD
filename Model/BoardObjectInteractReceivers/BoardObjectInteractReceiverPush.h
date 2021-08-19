#ifndef BOARD_OBJECT_INTERACT_RECEIVER_PUSH_H
#define BOARD_OBJECT_INTERACT_RECEIVER_PUSH_H

#include "BoardObjectInteractReceiver.h"

class BoardObjectInteractReceiverPush: public BoardObjectInteractReceiver
{
public:
	BoardObjectInteractReceiverPush();

protected:
	bool receiverTemplateMethod(std::string key, BoardObject* sender, BoardObject& me, Level& level) override;
};

#endif