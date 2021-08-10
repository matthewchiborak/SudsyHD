#include <iostream>

#include "Controller/GameController.h"
#include "View/View.h"
#include "Model/GameModel.h"
#include "Model/LevelFactory.h"
#include "View/RenderStrategyFactory.h"
#include "View/SpriteFlyweightFactory.h"

#include "Model/Point.h"

#include "Model/GameStates/GameStateWait.h"

int main()
{
	std::unique_ptr<IRenderStrategyFactory> renderStratFact = std::make_unique<RenderStrategyFactory>();
	std::unique_ptr<ISpriteFlyweightFactory> spriteFactory = std::make_unique<SpriteFlyweightFactory>("Textures/ModelPaths.json");
	std::unique_ptr<ILevelFactory> levelFactory = std::make_unique<LevelFactory>("Levels");
	std::unique_ptr<IGameModel> model = std::make_unique<GameModel>(*levelFactory);
	model.get()->setState(std::move(std::make_unique<GameStateWait>(*(model.get()))));
	std::unique_ptr<IView> view = std::make_unique<View>(Point(1600, 800), *(model.get()), *(renderStratFact.get()), *(spriteFactory.get()), "Shaders");
	std::unique_ptr<IGameController> controller = std::make_unique<GameController>(*(model.get()), *(view.get()));

	controller->start();

	return 0;
}