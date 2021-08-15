#ifndef BOARD_OBJECT_BEHAVIOUR_NONE_H
#define BOARD_OBJECT_BEHAVIOUR_NONE_H

#include "BoardObjectBehaviour.h"

class BoardObjectBehaviourNone: public BoardObjectBehaviour
{
public:
	BoardObjectBehaviourNone();

	void execute(float t, BoardObject& me, Level& level) override;
	bool wouldBeAbleToExecute(BoardObject& me, Level& level) override;
};

#endif