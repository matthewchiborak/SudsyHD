#include "RenderStrategyEnd.h"

#include "../IView.h"
#include "../../Model/BoardObjects/BoardObjectPauseScreen.h"

#include "../../Model/BoardObjectBehaviours/BoardObjectBehaviourNone.h"
#include "../../Model/BoardObjectInteractSenders/BoardObjectInteractSenderNone.h"
#include "../../Model/BoardObjectInteractReceivers/BoardObjectInteractReceiverNone.h"

#include <iostream>

RenderStrategyEnd::RenderStrategyEnd()
	: RenderStrategy()
{
	this->pauseScreen = std::move(std::make_unique<BoardObjectPauseScreen>(
		Point(4, 4),
		"End",
		std::move(std::make_unique<BoardObjectBehaviourNone>()),
		std::move(std::make_unique<BoardObjectInteractSenderNone>()),
		std::move(std::make_unique<BoardObjectInteractReceiverNone>())
		));
}

void RenderStrategyEnd::drawScene(IView& view)
{
	const Level* currentLevel = view.getModel()->getCurrentLevel();
	int boardWidth = currentLevel->getWidth();
	int boardHeight = currentLevel->getHeight();

	Camera* camera = view.getCamera();
	camera->setPosition(glm::vec3((float)boardWidth / 20.0f, 1.2f, (float)boardHeight / 20.0f));

	this->pauseScreen.get()->draw(view);
}
