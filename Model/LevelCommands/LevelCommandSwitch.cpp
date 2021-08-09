#include "LevelCommandSwitch.h"

LevelCommandSwitch::LevelCommandSwitch(LevelCommandMove* moveCmd, bool isNext)
	: LevelCommand(), moveCmd(moveCmd), isNext(isNext)
{
}

void LevelCommandSwitch::execute()
{
	moveCmd->switchPlayer(isNext);
}
