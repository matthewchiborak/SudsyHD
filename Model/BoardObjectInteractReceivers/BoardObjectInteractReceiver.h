#ifndef BOARD_OBJECT_INTERACT_RECEIVER_H
#define BOARD_OBJECT_INTERACT_RECEIVER_H

#include <string>
#include <memory>

class BoardObject;
class Level;

class BoardObjectInteractReceiver
{
public:
	BoardObjectInteractReceiver();

	bool execute(std::string key, BoardObject* sender, BoardObject& me, Level& level);
	void addChild(std::unique_ptr<BoardObjectInteractReceiver> child);

protected:
	//Composition so can have multi if need be
	bool hasChild;
	std::unique_ptr<BoardObjectInteractReceiver> child;
	virtual bool receiverTemplateMethod(std::string key, BoardObject* sender, BoardObject& me, Level& level) = 0;
};

#endif