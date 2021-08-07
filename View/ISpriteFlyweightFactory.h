#ifndef I_SPRITE_FLYWEIGHT_FACTORY_H
#define I_SPRITE_FLYWEIGHT_FACTORY_H

#include "Sprite.h"

class ISpriteFlyweightFactory
{
public:
	ISpriteFlyweightFactory();
	virtual ~ISpriteFlyweightFactory();

	virtual Sprite* getSprite(std::string key) = 0;

};

#endif