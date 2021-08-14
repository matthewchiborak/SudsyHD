#ifndef BOARD_OBJECT_ROCK_H
#define BOARD_OBJECT_ROCK_H

#include "BoardObject.h"

class BoardObjectRock: public BoardObject
{
public:
	BoardObjectRock(Point position, 
				std::string spriteKey, 
				std::unique_ptr<BoardObjectBehaviour> behaviour, 
				std::unique_ptr<BoardObjectInteractSender> interactSender,
				std::unique_ptr<BoardObjectInteractReceiver> interactReceiver
				);

	SpaceClaimResponse canIShareSpaceWithYou(std::string key) override;
	std::string getSpaceSharingKey() override;
};

#endif