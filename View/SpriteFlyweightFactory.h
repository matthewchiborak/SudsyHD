#ifndef SPRITE_FLYWEIGHT_FACTORY_H
#define SPRITE_FLYWEIGHT_FACTORY_H

#include <map>

#include "ISpriteFlyweightFactory.h"

class SpriteFlyweightFactory: public ISpriteFlyweightFactory
{
public:
	SpriteFlyweightFactory(std::string textureKeyListFilePath);
	~SpriteFlyweightFactory();

	Sprite* getSprite(std::string key) override;

private:
	std::string textureKeyListFilePath;
	std::string shaderFolderFilePath;
	std::map<std::string, Sprite*> flyweights;

	Sprite* createFlyweight(std::string key) throw();
};

#endif