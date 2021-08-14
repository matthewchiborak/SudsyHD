#ifndef BOARD_OBJECT_ENEMY_H
#define BOARD_OBJECT_ENEMY_H

#include "BoardObject.h"

class BoardObjectEnemy: public BoardObject
{
public:
	BoardObjectEnemy(Point position, 
				std::string spriteKey, 
				std::unique_ptr<BoardObjectBehaviour> behaviour, 
				std::unique_ptr<BoardObjectInteractSender> interactSender,
				std::unique_ptr<BoardObjectInteractReceiver> interactReceiver
				);

	SpaceClaimResponse canIShareSpaceWithYou(std::string key) override;
	std::string getSpaceSharingKey() override;
};

#endif