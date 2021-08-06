#include "BoardObject.h"

BoardObject::BoardObject(Point position)
	: position(position)
{
}

Point BoardObject::getPosition()
{
	return position;
}
