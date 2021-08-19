#ifndef BOARD_OBJECT_INTERACT_RECEIVER_FLOAT_H
#define BOARD_OBJECT_INTERACT_RECEIVER_FLOAT_H

#include "BoardObjectInteractReceiver.h"

class BoardObjectInteractReceiverFloat: public BoardObjectInteractReceiver
{
public:
	BoardObjectInteractReceiverFloat();

protected:
	bool receiverTemplateMethod(std::string key, BoardObject* sender, BoardObject& me, Level& level) override;
};

#endif