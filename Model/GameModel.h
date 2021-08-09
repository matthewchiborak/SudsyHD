#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include "IGameModel.h"

#include "GameStates/GameState.h"

class GameModel: public IGameModel
{
public:
	GameModel(ILevelFactory& levelFactory);

	void move(const Point direction) override;
	void interact() override;
	void advance() override;
	void change(bool next) override;

	void setState(std::unique_ptr<GameState> state);

private:
	std::unique_ptr<GameState> state;
};

#endif