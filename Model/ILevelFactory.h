#ifndef I_LEVEL_FACTORY_H
#define I_LEVEL_FACTORY_H

#include <memory>
#include <string>

#include "Level.h"

class ILevelFactory
{
public:
	ILevelFactory(std::string levelFileLocation);

	virtual std::unique_ptr<Level> createLevel(int level) throw() = 0;

protected:
	std::string levelFileLocation;
};

#endif