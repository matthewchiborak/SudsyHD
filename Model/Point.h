#ifndef POINT_H
#define POINT_H

#include <ostream>

class Point
{
public:
	Point(int x, int y);
	Point(const Point& copy);

	bool operator == (const Point& point2);
	friend std::ostream& operator<<(std::ostream& output, const Point& point);

	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);

private:
	int x;
	int y;
};

#endif