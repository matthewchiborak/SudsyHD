#ifndef RENDER_STRATEGY_BOARD_H
#define RENDER_STRATEGY_BOARD_H

#include "RenderStrategy.h"

class RenderStrategyBoard: public RenderStrategy
{
public:
	RenderStrategyBoard();

	void execute(	GLFWwindow* window, 
					Camera& camera, 
					unsigned const int width, 
					unsigned const int height, 
					ISpriteFlyweightFactory& spriteFactory,
					const IGameModel& model) override;

private:
	void drawScene(Camera& camera, ISpriteFlyweightFactory& spriteFactory, const IGameModel& model);

};

#endif