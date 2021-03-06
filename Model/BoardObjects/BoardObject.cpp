#include "BoardObject.h"

#include "../../View/IView.h"
#include "../../View/ISpriteFlyweightFactory.h"

BoardObject::BoardObject(Point position, 
						std::string spriteKey, 
						std::unique_ptr<BoardObjectBehaviour> behaviour,
						std::unique_ptr<BoardObjectInteractSender> interactSender,
						std::unique_ptr<BoardObjectInteractReceiver> interactReceiver,
						Point size
						)
	: position(position), 
	positionF(position.getX(), position.getY()), 
	spriteKey(spriteKey), 
	behaviour(std::move(behaviour)), 
	interactSender(std::move(interactSender)), 
	interactReceiver(std::move(interactReceiver)),
	lastDirFacing(0, -1),
	size(size)
{
	
}

BoardObject::~BoardObject()
{

}

void BoardObject::draw(IView& view) const
{
	ISpriteFlyweightFactory* factory = view.getSpriteFactory();
	Camera* camera = view.getCamera();
	Shader* shader = view.getShader();

	factory->getSprite(this->spriteKey)->Draw(
		*camera,
		*shader,
		this->size,
		glm::vec3((float)this->getPositionF().getX() / 10.0f, 
		0.001f, 
		(float)this->getPositionF().getY() / 10.0f)
	);
}

void BoardObject::advance(float t, Level& level)
{
	this->behaviour.get()->execute(t, *this, level);
}

bool BoardObject::isDoneAction()
{
	return behaviour.get()->isDone();
}

void BoardObject::setBehaviour(std::unique_ptr<BoardObjectBehaviour> behaviour)
{
	this->behaviour = std::move(behaviour);
}

bool BoardObject::interactSend(Level& level)
{
	return this->interactSender.get()->execute(*(this), level);
}

bool BoardObject::interactReceive(std::string key, BoardObject* sender, Level& level)
{
	return this->interactReceiver.get()->execute(key, sender, *(this), level);
}

void BoardObject::setLastDirFacing(Point dir)
{
	this->lastDirFacing = dir;
}

Point BoardObject::getLastDirFacing() const
{
	return lastDirFacing;
}

void BoardObject::setSpaceSharingKey(std::string key)
{
	this->spaceSharingKey = key;
}

void BoardObject::resetSpaceSharingKey()
{
	spaceSharingKey = originalSpaceSharingKey;
}

void BoardObject::setSpriteKey(std::string key)
{
	this->spriteKey = key;
}

void BoardObject::resetSpriteKey()
{
	this->spriteKey = originalSpriteKey;
}

std::string BoardObject::getSpriteKey() const
{
	return spriteKey;
}

void BoardObject::addInteractReceiver(std::unique_ptr<BoardObjectInteractReceiver> receiver)
{
	this->interactReceiver.get()->addChild(std::move(receiver));
}

Point BoardObject::getPosition() const
{
	return position;
}

PointF BoardObject::getPositionF() const
{
	return positionF;
}

void BoardObject::setPositionF(const PointF newPos)
{
	this->positionF = newPos;
}

void BoardObject::setPosition(const Point newPos)
{
	this->position = newPos;
}
