#ifndef BOARD_OBJECT_PIT_H
#define BOARD_OBJECT_PIT_H

#include "BoardObject.h"

class BoardObjectPit: public BoardObject
{
public:
	BoardObjectPit(Point position, 
				std::string spriteKey, 
				std::unique_ptr<BoardObjectBehaviour> behaviour, 
				std::unique_ptr<BoardObjectInteractSender> interactSender,
				std::unique_ptr<BoardObjectInteractReceiver> interactReceiver
				);

	SpaceClaimResponse canIShareSpaceWithYou(std::string key) override;
	std::string getSpaceSharingKey() override;
};

#endif