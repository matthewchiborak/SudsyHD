#include "BoardObject.h"

#include "../../View/IView.h"
#include "../../View/ISpriteFlyweightFactory.h"

BoardObject::BoardObject(Point position, std::string spriteKey)
	: position(position), spriteKey(spriteKey)
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
		glm::vec3((float)this->getPosition().getX() / 10.0f, 
		0.001f, 
		(float)this->getPosition().getY() / 10.0f)
	);
}

Point BoardObject::getPosition() const
{
	return position;
}
