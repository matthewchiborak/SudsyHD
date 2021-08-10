#ifndef POINT_F_H
#define POINT_F_H

#include <ostream>

class PointF
{
public:
	PointF(float x, float y);
	PointF(const PointF& copy);

	bool operator == (const PointF& point2);
	friend std::ostream& operator<<(std::ostream& output, const PointF& point);

	float getX() const;
	float getY() const;
	void setX(float x);
	void setY(float y);

private:
	float x;
	float y;
};

#endif