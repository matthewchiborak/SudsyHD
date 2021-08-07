#include <iostream>

#include "Controller/GameController.h"
#include "View/View.h"
#include "Model/GameModel.h"
#include "Model/LevelFactory.h"
#include "View/RenderStrategyFactory.h"
#include "View/SpriteFlyweightFactory.h"

#include "Model/Point.h"

int main()
{
	IRenderStrategyFactory* renderStratFact = new RenderStrategyFactory();
	ISpriteFlyweightFactory* spriteFactory = new SpriteFlyweightFactory("Textures/ModelPaths.json", "Shaders");
	ILevelFactory* levelFactory = new LevelFactory("Levels");
	IGameModel* model = new GameModel(*levelFactory);
	IView* view = new View(Point(1600, 800), *model, *renderStratFact, *spriteFactory);
	IGameController* controller = new GameController(*model, *view);

	controller->start();

	delete controller;
	delete view;
	delete model;
	delete levelFactory;
	delete renderStratFact;

	return 0;
}