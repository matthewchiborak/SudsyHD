#ifndef BOARD_OBJECT_BEHAVIOUR_MOVE_INFINITE_H
#define BOARD_OBJECT_BEHAVIOUR_MOVE_INFINITE_H

#include "BoardObjectBehaviour.h"

#include "../Point.h"

class BoardObjectBehaviourMoveInfinite: public BoardObjectBehaviour
{
public:
	BoardObjectBehaviourMoveInfinite(Point dir);

	void execute(float t, BoardObject& me, Level& level) override;
	bool wouldBeAbleToExecute(BoardObject& me, Level& level) override;

private:
	bool hasClaimedSpace;
	Point dir;
	int lastT;
	Point meOriginalPos;
	bool originalPosSet;
};

#endif