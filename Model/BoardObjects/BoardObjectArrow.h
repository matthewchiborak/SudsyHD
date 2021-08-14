#ifndef BOARD_OBJECT_ARROW_H
#define BOARD_OBJECT_ARROW_H

#include "BoardObject.h"

class BoardObjectArrow: public BoardObject
{
public:
	BoardObjectArrow(Point position, 
				std::string spriteKey, 
				std::unique_ptr<BoardObjectBehaviour> behaviour, 
				std::unique_ptr<BoardObjectInteractSender> interactSender,
				std::unique_ptr<BoardObjectInteractReceiver> interactReceiver
				);

	SpaceClaimResponse canIShareSpaceWithYou(std::string key) override;
	std::string getSpaceSharingKey() override;
};

#endif