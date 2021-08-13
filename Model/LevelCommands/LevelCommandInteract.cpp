#include "LevelCommandInteract.h"

#include <iostream>

#include "LevelCommandMove.h"

LevelCommandInteract::LevelCommandInteract(LevelCommandMove* moveCmd, Level& level)
	: LevelCommand(), moveCmd(moveCmd), level(&level)
{
}

void LevelCommandInteract::execute()
{
	this->moveCmd->getCurrentPlayer()->interactSend(*level);
}
