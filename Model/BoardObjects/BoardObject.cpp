#include "BoardObject.h"

#include "../../View/IView.h"
#include "../../View/ISpriteFlyweightFactory.h"

BoardObject::BoardObject(Point position, 
						std::string spriteKey, 
						std::unique_ptr<BoardObjectBehaviour> behaviour,
						std::unique_ptr<BoardObjectInteractSender> interactSender,
						std::unique_ptr<BoardObjectInteractReceiver> interactReceiver
						)
	: position(position), 
	positionF(position.getX(), position.getY()), 
	spriteKey(spriteKey), 
	behaviour(std::move(behaviour)), 
	interactSender(std::move(interactSender)), 
	interactReceiver(std::move(interactReceiver)),
	lastDirFacing(0, -1)
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
