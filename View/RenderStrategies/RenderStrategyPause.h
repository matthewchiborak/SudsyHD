#ifndef RENDER_STRATEGY_PAUSE_H
#define RENDER_STRATEGY_PAUSE_H

#include "RenderStrategy.h"

class RenderStrategyPause: public RenderStrategy
{
public:
	RenderStrategyPause();

	void drawScene(IView& view) override;

private:

	std::unique_ptr<BoardObject> pauseScreen;

};

#endif