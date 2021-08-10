#ifndef BOARD_OBJECT_BEHAVIOUR_MOVE_ONE_H
#define BOARD_OBJECT_BEHAVIOUR_MOVE_ONE_H

#include "BoardObjectBehaviour.h"

#include "../Point.h"

class BoardObjectBehaviourMoveOne: public BoardObjectBehaviour
{
public:
	BoardObjectBehaviourMoveOne(Point dir);

	void execute(float t, BoardObject& me, IGameModel& model) override;

private:
	Point dir;
};

#endif