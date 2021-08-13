#include "LevelFactory.h"

#include <fstream>
#include <streambuf>

#include "BoardObjects/BoardObject.h"

#include "LevelBoard.h"

#include "LevelCommands/LevelCommandMove.h"
#include "LevelCommands/LevelCommandInteract.h"
#include "LevelCommands/LevelCommandSwitch.h"

#include "BoardObjectBehaviours/BoardObjectBehaviourNone.h"

#include "BoardObjectInteractSenders/BoardObjectInteractSenderNone.h"
#include "BoardObjectInteractSenders/BoardObjectInteractSenderPush.h"

#include "BoardObjectInteractReceivers/BoardObjectInteractReceiverNone.h"
#include "BoardObjectInteractReceivers/BoardObjectInteractReceiverPush.h"

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

	std::unique_ptr<LevelBoard> newLevel = std::make_unique<LevelBoard>();

	std::ifstream t(filePath);
	std::string text((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
	JSON = nlohmann::json::parse(text);

	setLevelParameters(newLevel.get());
	createPlayersAndPlayerDependantCommands(newLevel.get());
	createEnemies(newLevel.get());
	createObstacles(newLevel.get());

	return newLevel;
}

bool LevelFactory::doesFileExist(const std::string& filePath)
{
	std::ifstream f(filePath.c_str());
	return f.good();
}

void LevelFactory::setLevelParameters(LevelBoard* levelBeingMade)
{
	levelBeingMade->setWidth(JSON["Width"]);
	levelBeingMade->setHeight(JSON["Height"]);
}

void LevelFactory::createPlayersAndPlayerDependantCommands(LevelBoard* levelBeingMade)
{
	std::unique_ptr<LevelCommandMove> moveCmd = std::make_unique<LevelCommandMove>();
	std::unique_ptr<LevelCommandInteract> interactCmd = std::make_unique<LevelCommandInteract>(moveCmd.get(), *levelBeingMade);
	std::unique_ptr<LevelCommandSwitch> switchNextCmd = std::make_unique<LevelCommandSwitch>(moveCmd.get(), true);
	std::unique_ptr<LevelCommandSwitch> switchNextCmd2 = std::make_unique<LevelCommandSwitch>(moveCmd.get(), false);

	for (int i = 0; i < JSON["Players"].size(); i++)
	{
		std::unique_ptr<BoardObject> newObject = std::make_unique<BoardObject>(
			Point(JSON["Players"][i]["X"], JSON["Players"][i]["Y"]), 
			std::string(JSON["Players"][i]["Key"]),
			std::move(std::make_unique<BoardObjectBehaviourNone>()),
			std::move(std::make_unique<BoardObjectInteractSenderPush>()),
			std::move(std::make_unique<BoardObjectInteractReceiverNone>())
			);
		moveCmd.get()->addPlayer(*(newObject.get()));
		levelBeingMade->addBoardObject(std::move(newObject));
	}

	levelBeingMade->setMoveCommand(std::move(moveCmd));
	levelBeingMade->setChangeNextCommand(std::move(switchNextCmd));
	levelBeingMade->setChangePrevCommand(std::move(switchNextCmd2));
	levelBeingMade->setInteractCommand(std::move(interactCmd));
}

void LevelFactory::createEnemies(LevelBoard* levelBeingMade)
{
	for (int i = 0; i < JSON["Enemies"].size(); i++)
	{
		std::unique_ptr<BoardObject> newObject = std::make_unique<BoardObject>(
			Point(JSON["Enemies"][i]["X"], JSON["Enemies"][i]["Y"]),
			std::string(JSON["Enemies"][i]["Key"]),
			std::move(std::make_unique<BoardObjectBehaviourNone>()),
			std::move(std::make_unique<BoardObjectInteractSenderNone>()),
			std::move(std::make_unique<BoardObjectInteractReceiverPush>())
			);
		levelBeingMade->addBoardObject(std::move(newObject));
	}
}

void LevelFactory::createObstacles(LevelBoard* levelBeingMade)
{
	for (int i = 0; i < JSON["Walls"].size(); i++)
	{
		std::unique_ptr<BoardObject> newObject = std::make_unique<BoardObject>(
			Point(JSON["Walls"][i]["X"], JSON["Walls"][i]["Y"]),
			std::string(JSON["Walls"][i]["Key"]),
			std::move(std::make_unique<BoardObjectBehaviourNone>()),
			std::move(std::make_unique<BoardObjectInteractSenderNone>()),
			std::move(std::make_unique<BoardObjectInteractReceiverNone>())
			);
		levelBeingMade->addBoardObject(std::move(newObject));
	}
}
