#ifndef I_VIEW_H
#define I_VIEW_H

#include "../Model/IGameModel.h"
#include "../Model/Point.h"

#include "IRenderStrategyFactory.h"
#include "ISpriteFlyweightFactory.h"
#include "RenderStrategies/RenderStrategy.h"

class IView
{
public:
	IView(
		Point windowSize,
		IGameModel& model,
		IRenderStrategyFactory& renderStratFactory,
		ISpriteFlyweightFactory& spriteFactory
	);
	virtual ~IView();

	virtual void draw() = 0;
	virtual void clearMemory() = 0;

	bool isWindowOpen();

	Camera* getCamera();
	const IGameModel* getModel() const;
	Point getWindowSize() const;
	GLFWwindow* getWindow() const;
	ISpriteFlyweightFactory* getSpriteFactory() const;
	Shader* getShader() const;

	void setRenderingStrategy(std::string key);

protected:
	Camera camera;
	IGameModel* model;
	Point windowSize;
	GLFWwindow* window;
	IRenderStrategyFactory* renderStratFactory;
	ISpriteFlyweightFactory* spriteFactory;
	std::unique_ptr<RenderStrategy> renderStrategy;

	Shader* cutoutShader;
};

#endif