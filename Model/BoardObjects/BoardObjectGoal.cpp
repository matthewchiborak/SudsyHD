#include "BoardObjectGoal.h"

BoardObjectGoal::BoardObjectGoal(Point position, std::string spriteKey, std::unique_ptr<BoardObjectBehaviour> behaviour, std::unique_ptr<BoardObjectInteractSender> interactSender, std::unique_ptr<BoardObjectInteractReceiver> interactReceiver)
	: BoardObject(position, spriteKey, std::move(behaviour), std::move(interactSender), std::move(interactReceiver))
{
}

SpaceClaimResponse BoardObjectGoal::canIShareSpaceWithYou(std::string key)
{
	if (key == "Person")
		return SpaceClaimResponse::ALLOW;
	if (key == "Enemy")
		return SpaceClaimResponse::ALLOW;

	return SpaceClaimResponse::DENY;
}

std::string BoardObjectGoal::getSpaceSharingKey()
{
	return "Goal";
}
