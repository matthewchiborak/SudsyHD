#ifndef RENDER_STRATEGY_WIN_H
#define RENDER_STRATEGY_WIN_H

#include "RenderStrategy.h"

class RenderStrategyWin: public RenderStrategy
{
public:
	RenderStrategyWin();

	void drawScene(IView& view) override;

private:

	std::unique_ptr<BoardObject> pauseScreen;

};

#endif