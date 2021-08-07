#ifndef I_GAME_MODEL_H
#define I_GAME_MODEL_H

#include "ILevelFactory.h"

class IGameModel
{
public:
	IGameModel(ILevelFactory& levelFactory);

	virtual void advance() = 0;

	void loadLevel(int level);

protected:
	ILevelFactory* levelFactory;
	std::unique_ptr<Level> currentLevel;
};

#endif