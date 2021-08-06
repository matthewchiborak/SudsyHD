#ifndef BOARD_OBJECT_H
#define BOARD_OBJECT_H

#include "../Point.h"

class BoardObject
{
public:
	BoardObject(Point position);

	Point getPosition();

protected:
	Point position;
};

#endif