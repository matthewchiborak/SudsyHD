#include "LevelCommandInteract.h"

#include <iostream>

#include "LevelCommandMove.h"

LevelCommandInteract::LevelCommandInteract(LevelCommandMove* moveCmd, Level& level)
	: LevelCommand(), moveCmd(moveCmd), level(&level)
{
}

bool LevelCommandInteract::execute()
{
	return this->moveCmd->getCurrentPlayer()->interactSend(*level);
}
