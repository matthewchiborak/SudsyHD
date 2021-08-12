#ifndef BOARD_OBJECT_H
#define BOARD_OBJECT_H

#include <string>
#include <memory>

#include "../Point.h"
#include "../PointF.h"
#include "../BoardObjectBehaviours/BoardObjectBehaviour.h"

class IView;

class BoardObject
{
public:
	BoardObject(Point position, std::string spriteKey, std::unique_ptr<BoardObjectBehaviour> behaviour);
	~BoardObject();

	Point getPosition() const;
	PointF getPositionF() const;
	void setPositionF(const PointF newPos);
	void setPosition(const Point newPos);

	void draw(IView& view) const;
	void advance(float t, Level& level);
	bool isDoneAction();

	void setBehaviour(std::unique_ptr<BoardObjectBehaviour> behaviour);

protected:
	Point position;
	PointF positionF;
	std::string spriteKey;
	std::unique_ptr<BoardObjectBehaviour> behaviour;
};

#endif