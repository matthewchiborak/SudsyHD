#include "RenderStrategyGameOver.h"

#include "../IView.h"
#include "../../Model/BoardObjects/BoardObjectPauseScreen.h"

#include "../../Model/BoardObjectBehaviours/BoardObjectBehaviourNone.h"
#include "../../Model/BoardObjectInteractSenders/BoardObjectInteractSenderNone.h"
#include "../../Model/BoardObjectInteractReceivers/BoardObjectInteractReceiverNone.h"

#include <iostream>

RenderStrategyGameOver::RenderStrategyGameOver()
	: RenderStrategy()
{
	this->pauseScreen = std::move(std::make_unique<BoardObjectPauseScreen>(
		Point(4, 4),
		"GameOver",
		std::move(std::make_unique<BoardObjectBehaviourNone>()),
		std::move(std::make_unique<BoardObjectInteractSenderNone>()),
		std::move(std::make_unique<BoardObjectInteractReceiverNone>())
		));
}

void RenderStrategyGameOver::drawScene(IView& view)
{
	const Level* currentLevel = view.getModel()->getCurrentLevel();
	int boardWidth = currentLevel->getWidth();
	int boardHeight = currentLevel->getHeight();

	Camera* camera = view.getCamera();
	camera->setPosition(glm::vec3((float)boardWidth / 20.0f, 1.2f, (float)boardHeight / 20.0f));

	this->pauseScreen.get()->draw(view);
}
