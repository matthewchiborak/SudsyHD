#ifndef I_GAME_MODEL_H
#define I_GAME_MODEL_H

#include "ILevelFactory.h"

class IGameModel
{
public:
	IGameModel(ILevelFactory& levelFactory);

	virtual void advance() = 0;
	virtual void move(const Point direction) = 0;
	virtual void interact() = 0;

	void loadLevel(int level);

	const Level* getCurrentLevel() const;

protected:
	ILevelFactory* levelFactory;
	std::unique_ptr<Level> currentLevel;
};

#endif