#ifndef I_VIEW_H
#define I_VIEW_H

#include "../Model/IGameModel.h"
#include "../Model/Point.h"

#include "RenderStrategies/RenderStrategy.h"

class IView
{
public:
	IView(
		Point windowSize,
		IGameModel& model
	);

	virtual void draw() = 0;
	virtual void clearMemory() = 0;

	bool isWindowOpen();

protected:
	IGameModel* model;
	Point windowSize;
	GLFWwindow* window;
	RenderStrategy* renderStrategy;
};

#endif