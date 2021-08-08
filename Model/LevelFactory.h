#ifndef LEVEL_FACTORY_H
#define LEVEL_FACTORY_H

#include <json/json.h>

#include "ILevelFactory.h"

class LevelBoard;

class LevelFactory: public ILevelFactory
{
public:
	LevelFactory(std::string levelFileLocation);

	std::unique_ptr<Level> createLevel(int level) throw() override;

private:
	nlohmann::json JSON;

	bool doesFileExist(const std::string& filePath);

	void setLevelParameters(Level* levelBeingMade);
	void createPlayers(Level* levelBeingMade);
	void createEnemies(Level* levelBeingMade);
	void createObstacles(Level* levelBeingMade);
};

#endif