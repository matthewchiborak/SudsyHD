#include "LevelCommandInteract.h"

#include <iostream>

LevelCommandInteract::LevelCommandInteract(LevelCommandMove* moveCmd)
	: LevelCommand(), moveCmd(moveCmd)
{
}

void LevelCommandInteract::execute()
{
	std::cout << "123 Level Command INteract called\n";
}
