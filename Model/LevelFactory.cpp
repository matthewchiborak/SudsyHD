#include "LevelFactory.h"

#include <fstream>
#include <streambuf>

#include "BoardObjects/BoardObjectArrow.h"
#include "BoardObjects/BoardObjectEnemy.h"
#include "BoardObjects/BoardObjectGoal.h"
#include "BoardObjects/BoardObjectPerson.h"
#include "BoardObjects/BoardObjectPit.h"
#include "BoardObjects/BoardObjectRock.h"

#include "LevelBoard.h"

#include "LevelCommands/LevelCommandMove.h"
#include "LevelCommands/LevelCommandInteract.h"
#include "LevelCommands/LevelCommandSwitch.h"

LevelFactory::LevelFactory(std::string levelFileLocation, IBehaviourFactory& behaviourFactory)
	: ILevelFactory(levelFileLocation, behaviourFactory)
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
	createPits(newLevel.get());
	createGoals(newLevel.get());

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
	std::unique_ptr<LevelCommandMove> moveCmd = std::make_unique<LevelCommandMove>(*levelBeingMade);
	std::unique_ptr<LevelCommandInteract> interactCmd = std::make_unique<LevelCommandInteract>(moveCmd.get(), *levelBeingMade);
	std::unique_ptr<LevelCommandSwitch> switchNextCmd = std::make_unique<LevelCommandSwitch>(moveCmd.get(), true);
	std::unique_ptr<LevelCommandSwitch> switchNextCmd2 = std::make_unique<LevelCommandSwitch>(moveCmd.get(), false);

	for (int i = 0; i < JSON["Players"].size(); i++)
	{
		std::unique_ptr<BoardObject> newObject = std::make_unique<BoardObjectPerson>(
			Point(JSON["Players"][i]["X"], JSON["Players"][i]["Y"]), 
			std::string(JSON["Players"][i]["Key"]),
			std::move(behaviourFactory->createBehaviour(JSON["Players"][i]["Behaviour"])),
			std::move(behaviourFactory->createSender(JSON["Players"][i]["Sender"])),
			std::move(behaviourFactory->createReceiver(JSON["Players"][i]["Receiver"]))
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
		std::unique_ptr<BoardObject> newObject = std::make_unique<BoardObjectEnemy>(
			Point(JSON["Enemies"][i]["X"], JSON["Enemies"][i]["Y"]),
			std::string(JSON["Enemies"][i]["Key"]),
			std::move(behaviourFactory->createBehaviour(JSON["Enemies"][i]["Behaviour"])),
			std::move(behaviourFactory->createSender(JSON["Enemies"][i]["Sender"])),
			std::move(behaviourFactory->createReceiver(JSON["Enemies"][i]["Receiver"]))
			);
		levelBeingMade->addBoardObject(std::move(newObject));
	}
}

void LevelFactory::createObstacles(LevelBoard* levelBeingMade)
{
	for (int i = 0; i < JSON["Obs"].size(); i++)
	{
		std::unique_ptr<BoardObject> newObject = std::make_unique<BoardObjectRock>(
			Point(JSON["Obs"][i]["X"], JSON["Obs"][i]["Y"]),
			std::string(JSON["Obs"][i]["Key"]),
			std::move(behaviourFactory->createBehaviour(JSON["Obs"][i]["Behaviour"])),
			std::move(behaviourFactory->createSender(JSON["Obs"][i]["Sender"])),
			std::move(behaviourFactory->createReceiver(JSON["Obs"][i]["Receiver"]))
			);
		levelBeingMade->addBoardObject(std::move(newObject));
	}
}

void LevelFactory::createPits(LevelBoard* levelBeingMade)
{
	for (int i = 0; i < JSON["Pits"].size(); i++)
	{
		std::unique_ptr<BoardObject> newObject = std::make_unique<BoardObjectPit>(
			Point(JSON["Pits"][i]["X"], JSON["Pits"][i]["Y"]),
			std::string(JSON["Pits"][i]["Key"]),
			std::move(behaviourFactory->createBehaviour(JSON["Pits"][i]["Behaviour"])),
			std::move(behaviourFactory->createSender(JSON["Pits"][i]["Sender"])),
			std::move(behaviourFactory->createReceiver(JSON["Pits"][i]["Receiver"]))
			);
		levelBeingMade->addBoardObject(std::move(newObject));
	}
}

void LevelFactory::createGoals(LevelBoard* levelBeingMade)
{
	for (int i = 0; i < JSON["Goals"].size(); i++)
	{
		std::unique_ptr<BoardObject> newObject = std::make_unique<BoardObjectGoal>(
			Point(JSON["Goals"][i]["X"], JSON["Goals"][i]["Y"]),
			std::string(JSON["Goals"][i]["Key"]),
			std::move(behaviourFactory->createBehaviour(JSON["Goals"][i]["Behaviour"])),
			std::move(behaviourFactory->createSender(JSON["Goals"][i]["Sender"])),
			std::move(behaviourFactory->createReceiver(JSON["Goals"][i]["Receiver"]))
			);
		levelBeingMade->addBoardObject(std::move(newObject));
	}
}
