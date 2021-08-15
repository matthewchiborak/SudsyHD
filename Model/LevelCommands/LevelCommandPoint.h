#ifndef LEVEL_COMMAND_POINT_H
#define LEVEL_COMMAND_POINT_H

#include "../Point.h"

class LevelCommandPoint
{
public:
	LevelCommandPoint();

	virtual bool execute(Point point) = 0;
};

#endif