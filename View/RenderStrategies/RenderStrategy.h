#ifndef RENDER_STRATEGY_H
#define RENDER_STRATEGY_H

#include "../Core/Mesh.h"
#include "../ISpriteFlyweightFactory.h"
#include "../../Model/IGameModel.h"

class IView;

class RenderStrategy
{
public:
	RenderStrategy();

	void execute(IView& view);
	virtual void drawScene(IView& view) = 0;

protected:
	std::string windowTitle;
	double prevTime;
	double crntTime;
	double timeDiff;
	// Keeps track of the amount of frames in timeDiff
	unsigned int counter;

	void drawFPS(GLFWwindow* window, std::string windowTitle);
	void clearScreen();
	void updateCamera(Camera& camera);
	void finishDrawing(GLFWwindow* window);
};

#endif