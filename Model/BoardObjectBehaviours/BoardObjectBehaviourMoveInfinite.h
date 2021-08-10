#ifndef BOARD_OBJECT_BEHAVIOUR_MOVE_INFINITE_H
#define BOARD_OBJECT_BEHAVIOUR_MOVE_INFINITE_H

#include "BoardObjectBehaviour.h"

#include "../Point.h"

class BoardObjectBehaviourMoveInfinite: public BoardObjectBehaviour
{
public:
	BoardObjectBehaviourMoveInfinite(Point dir);

	void execute(float t, BoardObject& me, IGameModel& model) override;

private:
	Point dir;
};

#endif