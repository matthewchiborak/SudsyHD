#ifndef BOARD_OBJECT_BEHAVIOUR_MOVE_ONE_H
#define BOARD_OBJECT_BEHAVIOUR_MOVE_ONE_H

#include "BoardObjectBehaviour.h"

#include "../Point.h"

class BoardObjectBehaviourMoveOne: public BoardObjectBehaviour
{
public:
	BoardObjectBehaviourMoveOne(Point dir, float t = 0);

	void execute(float t, BoardObject& me, Level& level) override;
	bool wouldBeAbleToExecute(BoardObject& me, Level& level) override;

private:
	Point dir;
	bool originalPosSet;
	Point meOriginalPos;
	float startingT;
	bool hasClaimedSpace;
};

#endif