#include "IView.h"

IView::IView(Point windowSize, IGameModel& model, IRenderStrategyFactory& renderStratFactory)
	: windowSize(windowSize), model(&model), renderStratFactory(&renderStratFactory)
{
}

bool IView::isWindowOpen()
{
	return !glfwWindowShouldClose(window);
}

