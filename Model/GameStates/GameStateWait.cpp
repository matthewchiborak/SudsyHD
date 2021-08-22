#include "GameStateWait.h"

#include <iostream>

#include "GameStateAction.h"
#include "GameStatePause.h"

#include "../../View/IView.h"

#include "../BoardObjects/BoardObjectPauseScreen.h"
#include "../BoardObjectBehaviours/BoardObjectBehaviourNone.h"
#include "../BoardObjectInteractSenders/BoardObjectInteractSenderNone.h"
#include "../BoardObjectInteractReceivers/BoardObjectInteractReceiverNone.h"

GameStateWait::GameStateWait(IGameModel& model, IView& view)
	: GameState(model, view)
{
	view.setRenderingStrategy("Board");
}

void GameStateWait::advance()
{

}

void GameStateWait::move(const Point direction)
{
	if (model->getCurrentLevel()->move(direction))
	{
		this->model->setState(std::move(std::make_unique<GameStateAction>(*model, *view)));
	}
}

void GameStateWait::interact()
{
	if (model->getCurrentLevel()->interact())
	{
		this->model->setState(std::move(std::make_unique<GameStateAction>(*model, *view)));
	}
}

void GameStateWait::change(bool next)
{
	model->getCurrentLevel()->change(next);
}

void GameStateWait::menuChange(bool next)
{
	this->model->setState(std::move(std::make_unique<GameStatePause>(*model, *view)));
}
