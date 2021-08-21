#include "LevelCommandSwitch.h"

LevelCommandSwitch::LevelCommandSwitch(LevelCommandMove* moveCmd, bool isNext)
	: LevelCommand(), moveCmd(moveCmd), isNext(isNext)
{
}

bool LevelCommandSwitch::execute()
{
	moveCmd->switchPlayer(isNext);
	return true;
}

void LevelCommandSwitch::draw(IView& view)
{
}
