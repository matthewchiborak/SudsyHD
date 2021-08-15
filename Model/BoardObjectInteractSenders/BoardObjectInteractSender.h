#ifndef BOARD_OBJECT_INTERACT_SENDER_H
#define BOARD_OBJECT_INTERACT_SENDER_H

#include <memory>

class BoardObject;
class Level;

class BoardObjectInteractSender
{
public:
	BoardObjectInteractSender();
	BoardObjectInteractSender(std::unique_ptr<BoardObjectInteractSender> child);

	bool execute(BoardObject& me, Level& level);

protected:
	//Composition so can have multi if need be
	bool hasChild;
	std::unique_ptr<BoardObjectInteractSender> child;
	virtual bool senderTemplateMethod(BoardObject& me, Level& level) = 0;
};

#endif