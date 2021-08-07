#include "SpriteFlyweightFactory.h"

#include <json/json.h>

SpriteFlyweightFactory::SpriteFlyweightFactory(std::string textureKeyListFilePath, std::string shaderFilePath)
	: textureKeyListFilePath(textureKeyListFilePath), shaderFolderFilePath(shaderFilePath), cutoutShader(nullptr)
{

}

SpriteFlyweightFactory::~SpriteFlyweightFactory()
{
	if (cutoutShader != nullptr)
	{
		cutoutShader->Delete();
		delete cutoutShader;
	}
	
	std::map<std::string, Sprite*>::iterator it;

	for (it = flyweights.begin(); it != flyweights.end(); it++)
	{
		delete it->second;
	}
}

Sprite* SpriteFlyweightFactory::getSprite(std::string key)
{
	if (cutoutShader == nullptr)
	{
		createShader();
		activateShader();
	}

	if (flyweights.find(key) == flyweights.end())
	{
		return createFlyweight(key);
	}

	return flyweights.at(key);
}

void SpriteFlyweightFactory::createShader()
{
	this->cutoutShader = new Shader((shaderFolderFilePath + "/default.vert").c_str(), (shaderFolderFilePath + "/cutout.frag").c_str(), (shaderFolderFilePath + "/default.geom").c_str());
}

void SpriteFlyweightFactory::activateShader()
{
	this->cutoutShader->Activate();
	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3  lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);
	glUniform4f(glGetUniformLocation(cutoutShader->ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(cutoutShader->ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
}

Sprite* SpriteFlyweightFactory::createFlyweight(std::string key) throw()
{
	std::ifstream t(textureKeyListFilePath);
	std::string text((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
	nlohmann::json JSON = nlohmann::json::parse(text);

	Sprite* newSprite = new Sprite(JSON[key]["Path"], *cutoutShader);
	flyweights.insert(std::pair<std::string, Sprite*>(key, newSprite));
	return newSprite;
}
