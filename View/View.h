#ifndef VIEW_H
#define VIEW_H

#include "IView.h"

class View: public IView
{
public:
	View(Point windowSize, IGameModel& model, IRenderStrategyFactory& renderStratFactory, ISpriteFlyweightFactory& spriteFactory, std::string shaderFilePath);
	~View();

	void draw() override;
	void clearMemory() override;

private:
	void setUp();

	void setUpWindow();
	void createWindow();
	void configureWindow();
	void createCamera();
	void createShader();
	
	std::string shaderFilePath;
};

#endif