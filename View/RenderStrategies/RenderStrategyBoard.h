#ifndef RENDER_STRATEGY_BOARD_H
#define RENDER_STRATEGY_BOARD_H

#include "RenderStrategy.h"

class RenderStrategyBoard: public RenderStrategy
{
public:
	RenderStrategyBoard();

	void execute(IView& view) override;

private:
	void drawScene(IView& view);

	void drawFloor(IView& view);
	void drawBoardObjects(IView& view);
	void drawText(IView& view);

};

#endif