#ifndef BOARD_OBJECT_H
#define BOARD_OBJECT_H

#include <string>

#include "../Point.h"

class IView;

class BoardObject
{
public:
	BoardObject(Point position, std::string spriteKey);
	~BoardObject();

	Point getPosition() const;

	void draw(IView& view) const;

protected:
	Point position;
	std::string spriteKey;
};

#endif