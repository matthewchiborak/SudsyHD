#ifndef RENDER_STRATEGY_BOARD_H
#define RENDER_STRATEGY_BOARD_H

#include "RenderStrategy.h"

class RenderStrategyBoard: public RenderStrategy
{
public:
	RenderStrategyBoard();

	void drawScene(IView& view) override;

private:

	void drawFloor(IView& view);
	void drawBoardObjects(IView& view);
	void drawText(IView& view);

};

#endif