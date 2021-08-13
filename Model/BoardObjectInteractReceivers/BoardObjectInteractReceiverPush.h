#ifndef BOARD_OBJECT_INTERACT_RECEIVER_PUSH_H
#define BOARD_OBJECT_INTERACT_RECEIVER_PUSH_H

#include "BoardObjectInteractReceiver.h"

class BoardObjectInteractReceiverPush: public BoardObjectInteractReceiver
{
public:
	BoardObjectInteractReceiverPush();
	BoardObjectInteractReceiverPush(std::unique_ptr<BoardObjectInteractReceiver> child);

protected:
	void receiverTemplateMethod(std::string key, BoardObject* sender, BoardObject& me, Level& level) override;
};

#endif