#include "IView.h"

IView::IView(Point windowSize, IGameModel& model, IRenderStrategyFactory& renderStratFactory, ISpriteFlyweightFactory& spriteFactory)
	: windowSize(windowSize), model(&model), renderStratFactory(&renderStratFactory), spriteFactory(&spriteFactory)
{
}

bool IView::isWindowOpen()
{
	return !glfwWindowShouldClose(window);
}

