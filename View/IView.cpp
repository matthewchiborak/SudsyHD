#include "IView.h"

IView::IView(Point windowSize, IGameModel& model, IRenderStrategyFactory& renderStratFactory, ISpriteFlyweightFactory& spriteFactory)
	: windowSize(windowSize), model(&model), renderStratFactory(&renderStratFactory), spriteFactory(&spriteFactory), cutoutShader(nullptr)
{

}

IView::~IView()
{
	if (cutoutShader != nullptr)
		delete cutoutShader;
}

bool IView::isWindowOpen()
{
	return !glfwWindowShouldClose(window);
}

Camera* IView::getCamera()
{
	return (&camera);
}

const IGameModel* IView::getModel() const
{
	return model;
}

Point IView::getWindowSize() const
{
	return windowSize;
}

GLFWwindow* IView::getWindow() const
{
	return window;
}

ISpriteFlyweightFactory* IView::getSpriteFactory() const
{
	return spriteFactory;
}

Shader* IView::getShader() const
{
	return this->cutoutShader;
}

void IView::setRenderingStrategy(std::string key)
{
	this->renderStrategy = std::move(this->renderStratFactory->createStrategy(key));
}
