#ifndef BOARD_OBJECT_INTERACT_RECEIVER_FREEZE_H
#define BOARD_OBJECT_INTERACT_RECEIVER_FREEZE_H

#include "BoardObjectInteractReceiver.h"

class BoardObjectInteractReceiverFreeze: public BoardObjectInteractReceiver
{
public:
	BoardObjectInteractReceiverFreeze();

protected:
	bool receiverTemplateMethod(std::string key, BoardObject* sender, BoardObject& me, Level& level) override;
};

#endif