#ifndef LEVEL_COMMAND_POINT_H
#define LEVEL_COMMAND_POINT_H

#include "../Point.h"

class LevelCommandPoint
{
public:
	LevelCommandPoint();

	virtual void execute(Point point) = 0;
};

#endif