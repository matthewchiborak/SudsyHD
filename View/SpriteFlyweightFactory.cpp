#include "SpriteFlyweightFactory.h"

#include <json/json.h>

SpriteFlyweightFactory::SpriteFlyweightFactory(std::string textureKeyListFilePath)
	: textureKeyListFilePath(textureKeyListFilePath)
{

}

SpriteFlyweightFactory::~SpriteFlyweightFactory()
{
	std::map<std::string, Sprite*>::iterator it;

	for (it = flyweights.begin(); it != flyweights.end(); it++)
	{
		delete it->second;
	}
}

Sprite* SpriteFlyweightFactory::getSprite(std::string key)
{
	if (flyweights.find(key) == flyweights.end())
	{
		return createFlyweight(key);
	}

	return flyweights.at(key);
}

Sprite* SpriteFlyweightFactory::createFlyweight(std::string key) throw()
{
	std::ifstream t(textureKeyListFilePath);
	std::string text((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
	nlohmann::json JSON = nlohmann::json::parse(text);

	Sprite* newSprite = new Sprite(JSON[key]["Path"]);
	flyweights.insert(std::pair<std::string, Sprite*>(key, newSprite));
	return newSprite;
}
