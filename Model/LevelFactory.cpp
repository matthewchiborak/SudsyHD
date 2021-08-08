#include "LevelFactory.h"

#include <fstream>
#include <streambuf>

#include "BoardObjects/BoardObject.h"

#include "LevelBoard.h"

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

	std::unique_ptr<Level> newLevel = std::make_unique<LevelBoard>();

	std::ifstream t(filePath);
	std::string text((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
	JSON = nlohmann::json::parse(text);

	setLevelParameters(newLevel.get());
	createPlayers(newLevel.get());
	createEnemies(newLevel.get());
	createObstacles(newLevel.get());

	return newLevel;
}

bool LevelFactory::doesFileExist(const std::string& filePath)
{
	std::ifstream f(filePath.c_str());
	return f.good();
}

void LevelFactory::setLevelParameters(Level* levelBeingMade)
{
	levelBeingMade->setWidth(JSON["Width"]);
	levelBeingMade->setHeight(JSON["Height"]);
}

void LevelFactory::createPlayers(Level* levelBeingMade)
{
	for (int i = 0; i < JSON["Players"].size(); i++)
	{
		std::unique_ptr<BoardObject> newObject = std::make_unique<BoardObject>(
			Point(JSON["Players"][i]["X"], JSON["Players"][i]["Y"]), 
			std::string(JSON["Players"][i]["Key"])
			);
		levelBeingMade->addBoardObject(std::move(newObject));
	}
}

void LevelFactory::createEnemies(Level* levelBeingMade)
{
	for (int i = 0; i < JSON["Enemies"].size(); i++)
	{
		std::unique_ptr<BoardObject> newObject = std::make_unique<BoardObject>(
			Point(JSON["Enemies"][i]["X"], JSON["Enemies"][i]["Y"]),
			std::string(JSON["Enemies"][i]["Key"])
			);
		levelBeingMade->addBoardObject(std::move(newObject));
	}
}

void LevelFactory::createObstacles(Level* levelBeingMade)
{
	for (int i = 0; i < JSON["Walls"].size(); i++)
	{
		std::unique_ptr<BoardObject> newObject = std::make_unique<BoardObject>(
			Point(JSON["Walls"][i]["X"], JSON["Walls"][i]["Y"]),
			std::string(JSON["Walls"][i]["Key"])
			);
		levelBeingMade->addBoardObject(std::move(newObject));
	}
}
