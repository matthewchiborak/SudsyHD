#include "PointF.h"

PointF::PointF(float x, float y)
	: x(x), y(y)
{
}

PointF::PointF(const PointF& copy)
{
	this->x = copy.getX();
	this->y = copy.getY();
}

bool PointF::operator==(const PointF& PointF2)
{
	return ((this->x == PointF2.getX()) && (this->y == PointF2.getY()));
}

float PointF::getX() const
{
	return x;
}

float PointF::getY() const
{
	return y;
}

void PointF::setX(float x)
{
	this->x = x;
}

void PointF::setY(float y)
{
	this->y = y;
}

std::ostream& operator<<(std::ostream& output, const PointF& PointF)
{
	output << "X: " << PointF.getX() << " Y: " << PointF.getY();
	return output;
}
