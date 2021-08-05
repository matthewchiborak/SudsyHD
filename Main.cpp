#include <iostream>

#include "Controller/GameController.h"
#include "View/View.h"
#include "Model/GameModel.h"

int main()
{
	std::cout << "Hello There\n";

	IGameModel model;
	IView view(model);
	GameController controller(model, view);

	return 0;
}