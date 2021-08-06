#include <iostream>

#include "Controller/GameController.h"
#include "View/View.h"
#include "Model/GameModel.h"

#include "Model/Point.h"

int main()
{
	IGameModel* model = new GameModel();
	IView* view = new View(Point(1600, 800), *model);
	GameController controller(*model, *view);

	controller.start();

	delete view;
	delete model;

	return 0;
}