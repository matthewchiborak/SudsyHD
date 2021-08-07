#ifndef I_VIEW_H
#define I_VIEW_H

#include "../Model/IGameModel.h"
#include "../Model/Point.h"

#include "IRenderStrategyFactory.h"
#include "RenderStrategies/RenderStrategy.h"

class IView
{
public:
	IView(
		Point windowSize,
		IGameModel& model,
		IRenderStrategyFactory& renderStratFactory
	);

	virtual void draw() = 0;
	virtual void clearMemory() = 0;

	bool isWindowOpen();

protected:
	IGameModel* model;
	Point windowSize;
	GLFWwindow* window;
	IRenderStrategyFactory* renderStratFactory;
	std::unique_ptr<RenderStrategy> renderStrategy;
};

#endif