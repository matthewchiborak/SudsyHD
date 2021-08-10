#ifndef BOARD_OBJECT_BEHAVIOUR_H
#define BOARD_OBJECT_BEHAVIOUR_H

class BoardObject;
class IGameModel;

class BoardObjectBehaviour
{
public:
	BoardObjectBehaviour();

	virtual void execute(float t, BoardObject& me, IGameModel& model) = 0;
	bool isDone();

protected:
	bool actionDone;

};

#endif