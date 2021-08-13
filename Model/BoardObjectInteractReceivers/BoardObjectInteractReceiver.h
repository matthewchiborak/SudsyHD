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
	BoardObjectInteractReceiver(std::unique_ptr<BoardObjectInteractReceiver> child);

	void execute(std::string key, BoardObject* sender, BoardObject& me, Level& level);

protected:
	//Composition so can have multi if need be
	bool hasChild;
	std::unique_ptr<BoardObjectInteractReceiver> child;
	virtual void receiverTemplateMethod(std::string key, BoardObject* sender, BoardObject& me, Level& level) = 0;
};

#endif