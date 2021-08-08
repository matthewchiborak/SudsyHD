#include "RenderStrategyBoard.h"

#include "../IView.h"
#include "../../Model/BoardObjects/BoardObject.h"

RenderStrategyBoard::RenderStrategyBoard()
	: RenderStrategy()
{
}

void RenderStrategyBoard::execute(IView& view)
{
	drawFPS(view.getWindow(), "Sudsy HD");
	clearScreen();
	updateCamera(*view.getCamera());
	drawScene(view);
	finishDrawing(view.getWindow());
}

void RenderStrategyBoard::drawScene(IView& view)
{
	drawFloor(view);
	drawBoardObjects(view);
}

void RenderStrategyBoard::drawFloor(IView& view)
{
	const Level* currentLevel = view.getModel()->getCurrentLevel();
	int boardWidth = currentLevel->getWidth();
	int boardHeight = currentLevel->getHeight();

	Camera* camera = view.getCamera();
	camera->setPosition(glm::vec3((float)boardWidth / 20.0f, 1.2f, (float)boardHeight / 20.0f));

	Shader* shader = view.getShader();

	ISpriteFlyweightFactory* factory = view.getSpriteFactory();

	for (int i = 0; i < boardWidth; i++)
	{
		for (int j = 0; j < boardHeight; j++)
		{
			factory->getSprite("Tile")->Draw(*camera, *shader, glm::vec3((float)i / 10.0f, 0.0f, (float)j / 10.0f));
		}
	}
}

void RenderStrategyBoard::drawBoardObjects(IView& view)
{
	const Level* currentLevel = view.getModel()->getCurrentLevel();
	const std::vector<std::unique_ptr<BoardObject>>* objects = currentLevel->getBoardObjects();

	for (int i = 0; i < objects->size(); i++)
	{
		(*objects)[i].get()->draw(view);
	}
}
