#ifndef LEVEL_COMMAND_POINT_H
#define LEVEL_COMMAND_POINT_H

#include "../Point.h"

class IView;


class LevelCommandPoint
{
public:
	LevelCommandPoint();

	virtual bool execute(Point point) = 0;
	virtual void draw(IView& view) = 0;
};

#endif