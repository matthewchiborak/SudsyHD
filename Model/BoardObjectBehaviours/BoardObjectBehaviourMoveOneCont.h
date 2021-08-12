#ifndef BOARD_OBJECT_BEHAVIOUR_MOVE_ONE_CONT_H
#define BOARD_OBJECT_BEHAVIOUR_MOVE_ONE_CONT_H

#include "BoardObjectBehaviour.h"

#include "../Point.h"

class BoardObjectBehaviourMoveOneCont: public BoardObjectBehaviour
{
public:
	BoardObjectBehaviourMoveOneCont(Point dir);

	void execute(float t, BoardObject& me, Level& level) override;

private:
	Point dir;
};

#endif