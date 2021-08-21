#include "BoardObjectPauseScreen.h"

BoardObjectPauseScreen::BoardObjectPauseScreen(Point position, std::string spriteKey, std::unique_ptr<BoardObjectBehaviour> behaviour, std::unique_ptr<BoardObjectInteractSender> interactSender, std::unique_ptr<BoardObjectInteractReceiver> interactReceiver)
	: BoardObject(position, spriteKey, std::move(behaviour), std::move(interactSender), std::move(interactReceiver), Point(16, 9))
{
	this->spaceSharingKey = "PauseScreen";
	this->originalSpaceSharingKey = this->spaceSharingKey;
	this->originalSpriteKey = spriteKey;

	this->setPositionF(PointF(4.f, 4.f));
}

SpaceClaimResponse BoardObjectPauseScreen::canIShareSpaceWithYou(std::string key)
{
	return SpaceClaimResponse::DENY;
}

std::string BoardObjectPauseScreen::getSpaceSharingKey()
{
	return spaceSharingKey;
}
