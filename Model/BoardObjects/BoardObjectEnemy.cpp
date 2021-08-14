#include "BoardObjectEnemy.h"

BoardObjectEnemy::BoardObjectEnemy(Point position, std::string spriteKey, std::unique_ptr<BoardObjectBehaviour> behaviour, std::unique_ptr<BoardObjectInteractSender> interactSender, std::unique_ptr<BoardObjectInteractReceiver> interactReceiver)
	: BoardObject(position, spriteKey, std::move(behaviour), std::move(interactSender), std::move(interactReceiver))
{
}

SpaceClaimResponse BoardObjectEnemy::canIShareSpaceWithYou(std::string key)
{
	if (key == "Rock")
		return SpaceClaimResponse::STOP;
	if (key == "Arrow")
		return SpaceClaimResponse::STOP;

	return SpaceClaimResponse::DENY;
}

std::string BoardObjectEnemy::getSpaceSharingKey()
{
	return "Enemy";
}
