#ifndef LEVEL_FACTORY_H
#define LEVEL_FACTORY_H

#include <json/json.h>

#include "ILevelFactory.h"

class LevelBoard;

class LevelFactory: public ILevelFactory
{
public:
	LevelFactory(std::string levelFileLocation, IBehaviourFactory& behaviourFactory);

	std::unique_ptr<Level> createLevel(int level) throw() override;

private:
	nlohmann::json JSON;

	bool doesFileExist(const std::string& filePath);

	void setLevelParameters(LevelBoard* levelBeingMade);
	void createPlayersAndPlayerDependantCommands(LevelBoard* levelBeingMade);
	void createEnemies(LevelBoard* levelBeingMade);
	void createObstacles(LevelBoard* levelBeingMade);
	void createPits(LevelBoard* levelBeingMade);
	void createGoals(LevelBoard* levelBeingMade);
};

#endif