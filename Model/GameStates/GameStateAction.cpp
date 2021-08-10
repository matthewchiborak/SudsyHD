#include "GameStateAction.h"

GameStateAction::GameStateAction(IGameModel& model)
	: GameState(model)
{
}

void GameStateAction::advance()
{
	model->getCurrentLevel()->advance(*model);
}

void GameStateAction::move(const Point direction)
{

}

void GameStateAction::interact()
{

}

void GameStateAction::change(bool next)
{

}
