#ifndef I_GAME_MODEL_H
#define I_GAME_MODEL_H

class IGameModel
{
public:
	IGameModel();

	virtual void advance() = 0;
};

#endif