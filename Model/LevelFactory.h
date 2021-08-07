#ifndef LEVEL_FACTORY_H
#define LEVEL_FACTORY_H

#include "ILevelFactory.h"

class LevelFactory: public ILevelFactory
{
public:
	LevelFactory(std::string levelFileLocation);

	std::unique_ptr<Level> createLevel(int level) throw() override;

private:
	bool doesFileExist(const std::string& filePath);
};

#endif