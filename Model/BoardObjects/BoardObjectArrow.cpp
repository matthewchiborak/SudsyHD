#include "BoardObjectArrow.h"

BoardObjectArrow::BoardObjectArrow(Point position, std::string spriteKey, std::unique_ptr<BoardObjectBehaviour> behaviour, std::unique_ptr<BoardObjectInteractSender> interactSender, std::unique_ptr<BoardObjectInteractReceiver> interactReceiver)
	: BoardObject(position, spriteKey, std::move(behaviour), std::move(interactSender), std::move(interactReceiver))
{
}

SpaceClaimResponse BoardObjectArrow::canIShareSpaceWithYou(std::string key)
{
	return SpaceClaimResponse::DENY;
}

std::string BoardObjectArrow::getSpaceSharingKey()
{
	return "Arrow";
}
