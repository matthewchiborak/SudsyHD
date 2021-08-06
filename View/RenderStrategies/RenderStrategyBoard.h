#ifndef RENDER_STRATEGY_BOARD_H
#define RENDER_STRATEGY_BOARD_H

#include "RenderStrategy.h"

class RenderStrategyBoard: public RenderStrategy
{
public:
	RenderStrategyBoard();

	void execute(GLFWwindow* window, Camera& camera, unsigned const int width, unsigned const int height) override;

private:
	double prevTime;
	double crntTime;
	double timeDiff;
	// Keeps track of the amount of frames in timeDiff
	unsigned int counter;

	void drawFPS(GLFWwindow* window);
	void clearScreen();
	void updateCamera(Camera& camera);
	void drawScene(const Camera& camera);

};

#endif