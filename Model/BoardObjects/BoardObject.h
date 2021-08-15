#ifndef BOARD_OBJECT_H
#define BOARD_OBJECT_H

#include <string>
#include <memory>

#include "../Point.h"
#include "../PointF.h"
#include "../BoardObjectBehaviours/BoardObjectBehaviour.h"
#include "../BoardObjectInteractSenders/BoardObjectInteractSender.h"
#include "../BoardObjectInteractReceivers/BoardObjectInteractReceiver.h"

#include "../SpaceClaimResponses.h"

class IView;

class BoardObject
{
public:
	BoardObject(Point position, 
				std::string spriteKey, 
				std::unique_ptr<BoardObjectBehaviour> behaviour, 
				std::unique_ptr<BoardObjectInteractSender> interactSender,
				std::unique_ptr<BoardObjectInteractReceiver> interactReceiver
				);
	~BoardObject();

	Point getPosition() const;
	PointF getPositionF() const;
	void setPositionF(const PointF newPos);
	void setPosition(const Point newPos);

	void draw(IView& view) const;
	void advance(float t, Level& level);
	bool isDoneAction();

	void setBehaviour(std::unique_ptr<BoardObjectBehaviour> behaviour);

	bool interactSend(Level& level);
	bool interactReceive(std::string key, BoardObject* sender, Level& level);

	void setLastDirFacing(Point dir);
	Point getLastDirFacing() const;

	virtual SpaceClaimResponse canIShareSpaceWithYou(std::string key) = 0;
	virtual std::string getSpaceSharingKey() = 0;
	void setSpaceSharingKey(std::string key);

	std::string getSpriteKey() const;

protected:
	Point position;
	PointF positionF;
	std::string spriteKey;
	std::string spaceSharingKey;
	std::unique_ptr<BoardObjectBehaviour> behaviour;
	std::unique_ptr<BoardObjectInteractSender> interactSender;
	std::unique_ptr<BoardObjectInteractReceiver> interactReceiver;
	Point lastDirFacing;
};

#endif