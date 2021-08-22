#ifndef RENDER_STRATEGY_END_H
#define RENDER_STRATEGY_END_H

#include "RenderStrategy.h"

class RenderStrategyEnd: public RenderStrategy
{
public:
	RenderStrategyEnd();

	void drawScene(IView& view) override;

private:

	std::unique_ptr<BoardObject> pauseScreen;

};

#endif