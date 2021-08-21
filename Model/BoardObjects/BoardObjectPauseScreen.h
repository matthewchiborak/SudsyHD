#ifndef BOARD_OBJECT_PAUSE_SCREEN_H
#define BOARD_OBJECT_PAUSE_SCREEN_H

#include "BoardObject.h"

class BoardObjectPauseScreen: public BoardObject
{
public:
	BoardObjectPauseScreen(Point position,
				std::string spriteKey, 
				std::unique_ptr<BoardObjectBehaviour> behaviour, 
				std::unique_ptr<BoardObjectInteractSender> interactSender,
				std::unique_ptr<BoardObjectInteractReceiver> interactReceiver
				);

	SpaceClaimResponse canIShareSpaceWithYou(std::string key) override;
	std::string getSpaceSharingKey() override;
};

#endif