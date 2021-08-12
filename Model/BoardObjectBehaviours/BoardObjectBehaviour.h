#ifndef BOARD_OBJECT_BEHAVIOUR_H
#define BOARD_OBJECT_BEHAVIOUR_H

class BoardObject;
class Level;

class BoardObjectBehaviour
{
public:
	BoardObjectBehaviour();

	virtual void execute(float t, BoardObject& me, Level& level) = 0;
	bool isDone();

protected:
	bool actionDone;

};

#endif