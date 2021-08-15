#include "BoardObjectPit.h"

BoardObjectPit::BoardObjectPit(Point position, std::string spriteKey, std::unique_ptr<BoardObjectBehaviour> behaviour, std::unique_ptr<BoardObjectInteractSender> interactSender, std::unique_ptr<BoardObjectInteractReceiver> interactReceiver)
	: BoardObject(position, spriteKey, std::move(behaviour), std::move(interactSender), std::move(interactReceiver))
{
}

SpaceClaimResponse BoardObjectPit::canIShareSpaceWithYou(std::string key)
{
	if (key == "Rock")
		return SpaceClaimResponse::STOP;
	if (key == "Arrow" || key == "Rock-Float")
		return SpaceClaimResponse::ALLOW;

	return SpaceClaimResponse::DENY;
}

std::string BoardObjectPit::getSpaceSharingKey()
{
	return "Pit";
}
