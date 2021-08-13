#ifndef BOARD_OBJECT_INTERACT_RECEIVER_NONE_H
#define BOARD_OBJECT_INTERACT_RECEIVER_NONE_H

#include "BoardObjectInteractReceiver.h"

class BoardObjectInteractReceiverNone: public BoardObjectInteractReceiver
{
public:
	BoardObjectInteractReceiverNone();

protected:
	void receiverTemplateMethod(std::string key, BoardObject* sender, BoardObject& me, Level& level) override;
};

#endif