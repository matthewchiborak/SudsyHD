#include "LevelFactory.h"

#include <fstream>
#include <streambuf>
#include <json/json.h>

#include "BoardObjects/BoardObject.h"

LevelFactory::LevelFactory(std::string levelFileLocation)
	: ILevelFactory(levelFileLocation)
{
}

std::unique_ptr<Level> LevelFactory::createLevel(int level) throw()
{
	std::string filePath = this->levelFileLocation + "/" + std::to_string(level) + ".json";

	if (!doesFileExist(filePath))
	{
		throw std::exception();
	}

	std::unique_ptr<Level> newLevel = std::make_unique<Level>();

	std::ifstream t(filePath);
	std::string text((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
	nlohmann::json JSON = nlohmann::json::parse(text);

	newLevel.get()->setWidth(JSON["Width"]);
	newLevel.get()->setHeight(JSON["Height"]);

	std::unique_ptr<BoardObject> newObject = std::make_unique<BoardObject>(Point(2, 2), "Duke");
	newLevel.get()->addBoardObject(std::move(newObject));

	return newLevel;
}

bool LevelFactory::doesFileExist(const std::string& filePath)
{
	std::ifstream f(filePath.c_str());
	return f.good();
}
