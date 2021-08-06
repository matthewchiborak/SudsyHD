#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include "IGameModel.h"

#include "GameStates/GameContext.h"

class GameModel: public IGameModel
{
public:
	GameModel();

	void advance() override;

private:
	GameContext context;
};

#endif