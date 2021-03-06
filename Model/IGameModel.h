#ifndef I_GAME_MODEL_H
#define I_GAME_MODEL_H

#include "ILevelFactory.h"

class GameState;

class IGameModel
{
public:
	IGameModel(ILevelFactory& levelFactory);

	virtual void advance() = 0;
	virtual void move(const Point direction) = 0;
	virtual void interact() = 0;
	virtual void change(bool next) = 0;
	virtual void changeMenu(bool next) = 0;

	bool loadLevel(int level);
	void reloadCurrentLevel();
	bool loadNextLevel();

	Level* getCurrentLevel() const;

	void setState(std::unique_ptr<GameState> state);

protected:
	int currentLevelNumber;
	std::unique_ptr<GameState> state;
	ILevelFactory* levelFactory;
	std::unique_ptr<Level> currentLevel;
};

#endif