#ifndef RENDER_STRATEGY_GAME_OVER_H
#define RENDER_STRATEGY_GAME_OVER_H

#include "RenderStrategy.h"

class RenderStrategyGameOver: public RenderStrategy
{
public:
	RenderStrategyGameOver();

	void drawScene(IView& view) override;

private:

	std::unique_ptr<BoardObject> pauseScreen;

};

#endif