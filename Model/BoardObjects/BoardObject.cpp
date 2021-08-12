#include "BoardObject.h"

#include "../../View/IView.h"
#include "../../View/ISpriteFlyweightFactory.h"

BoardObject::BoardObject(Point position, std::string spriteKey, std::unique_ptr<BoardObjectBehaviour> behaviour)
	: position(position), positionF(position.getX(), position.getY()), spriteKey(spriteKey), behaviour(std::move(behaviour))
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
