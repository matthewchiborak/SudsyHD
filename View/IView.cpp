#include "IView.h"

IView::IView(Point windowSize, IGameModel& model)
	: windowSize(windowSize), model(&model)
{
}

bool IView::isWindowOpen()
{
	return !glfwWindowShouldClose(window);
}

