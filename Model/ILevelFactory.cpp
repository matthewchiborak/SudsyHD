#include "ILevelFactory.h"

ILevelFactory::ILevelFactory(std::string levelFileLocation, IBehaviourFactory& behaviourFactory)
	: levelFileLocation(levelFileLocation), behaviourFactory(&behaviourFactory)
{
}
