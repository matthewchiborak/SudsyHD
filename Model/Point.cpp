#include "Point.h"

Point::Point(int x, int y)
	: x(x), y(y)
{
}

Point::Point(const Point& copy)
{
	this->x = copy.getX();
	this->y = copy.getY();
}

bool Point::operator==(const Point& point2)
{
	return ((this->x == point2.getX()) && (this->y == point2.getY()));
}

Point Point::operator+(const Point& point2)
{
	return Point(this->x + point2.getX(), this->y + point2.getY());
}

int Point::getX() const
{
	return x;
}

int Point::getY() const
{
	return y;
}

void Point::setX(int x)
{
	this->x = x;
}

void Point::setY(int y)
{
	this->y = y;
}

std::ostream& operator<<(std::ostream& output, const Point& point)
{
	output << "X: " << point.getX() << " Y: " << point.getY();
	return output;
}
