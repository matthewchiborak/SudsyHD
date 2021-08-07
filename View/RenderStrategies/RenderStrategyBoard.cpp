#include "RenderStrategyBoard.h"

RenderStrategyBoard::RenderStrategyBoard()
	: RenderStrategy()
{
}

void RenderStrategyBoard::execute(	GLFWwindow* window, 
									Camera& camera, 
									unsigned const int width, 
									unsigned const int height, 
									ISpriteFlyweightFactory& spriteFactory,
									const IGameModel& model)
{
	drawFPS(window, "Sudsy HD");
	clearScreen();
	//camera->Inputs(window);
	updateCamera(camera);
	drawScene(camera, spriteFactory, model);
	finishDrawing(window);
}

void RenderStrategyBoard::drawScene(Camera& camera, ISpriteFlyweightFactory& spriteFactory, const IGameModel& model)
{
	int boardWidth = model.getCurrentLevel()->getWidth();
	int boardHeight = model.getCurrentLevel()->getHeight();

	camera.setPosition(glm::vec3((float)boardWidth / 20.0f, 1.2f, (float)boardHeight / -20.0f));

	for (int i = 0; i < boardWidth; i++)
	{
		for (int j = 0; j < boardHeight; j++)
		{
			spriteFactory.getSprite("Tile")->Draw(camera, glm::vec3((float)i / 10.0f, 0.0f, (float)j / -10.0f));
		}
	}
}
