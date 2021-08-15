#include "BehaviourFactory.h"

#include <iostream>

#include "BoardObjectBehaviours/BoardObjectBehaviourMoveInfinite.h"
#include "BoardObjectBehaviours/BoardObjectBehaviourMoveOne.h"
#include "BoardObjectBehaviours/BoardObjectBehaviourMoveOneCont.h"
#include "BoardObjectBehaviours/BoardObjectBehaviourNone.h"

#include "BoardObjectInteractSenders/BoardObjectInteractSenderNone.h"
#include "BoardObjectInteractSenders/BoardObjectInteractSenderPush.h"
#include "BoardObjectInteractSenders/BoardObjectInteractSenderShoot.h"
#include "BoardObjectInteractSenders/BoardObjectInteractSenderFreeze.h"

#include "BoardObjectInteractReceivers/BoardObjectInteractReceiverNone.h"
#include "BoardObjectInteractReceivers/BoardObjectInteractReceiverPush.h"
#include "BoardObjectInteractReceivers/BoardObjectInteractReceiverFreeze.h"

BehaviourFactory::BehaviourFactory()
	: IBehaviourFactory()
{
}

std::unique_ptr<BoardObjectBehaviour> BehaviourFactory::createBehaviour(std::string key) throw()
{
	if(key == "NONE")
		return std::move(std::make_unique<BoardObjectBehaviourNone>());

	if(key == "MOVE_ONE_LEFT")
		return std::move(std::make_unique<BoardObjectBehaviourMoveOne>(Point(1, 0)));
	if (key == "MOVE_ONE_RIGHT")
		return std::move(std::make_unique<BoardObjectBehaviourMoveOne>(Point(-1, 0)));
	if (key == "MOVE_ONE_UP")
		return std::move(std::make_unique<BoardObjectBehaviourMoveOne>(Point(0, 1)));
	if (key == "MOVE_ONE_DOWN")
		return std::move(std::make_unique<BoardObjectBehaviourMoveOne>(Point(0, -1)));
	
	if(key == "MOVE_ONE_CONT_LEFT")
		return std::move(std::make_unique<BoardObjectBehaviourMoveOneCont>(Point(1, 0)));
	if (key == "MOVE_ONE_CONT_RIGHT")
		return std::move(std::make_unique<BoardObjectBehaviourMoveOneCont>(Point(-1, 0)));
	if (key == "MOVE_ONE_CONT_UP")
		return std::move(std::make_unique<BoardObjectBehaviourMoveOneCont>(Point(0, 1)));
	if (key == "MOVE_ONE_CONT_DOWN")
		return std::move(std::make_unique<BoardObjectBehaviourMoveOneCont>(Point(0, -1)));

	if(key == "MOVE_INFINITE_LEFT")
		return std::move(std::make_unique<BoardObjectBehaviourMoveInfinite>(Point(1, 0)));
	if (key == "MOVE_INFINITE_RIGHT")
		return std::move(std::make_unique<BoardObjectBehaviourMoveInfinite>(Point(-1, 0)));
	if (key == "MOVE_INFINITE_UP")
		return std::move(std::make_unique<BoardObjectBehaviourMoveInfinite>(Point(0, 1)));
	if (key == "MOVE_INFINITE_DOWN")
		return std::move(std::make_unique<BoardObjectBehaviourMoveInfinite>(Point(0, -1)));

	std::cout << key << " : Unfound Behavour\n";

	throw key;
}

std::unique_ptr<BoardObjectInteractSender> BehaviourFactory::createSender(std::string key) throw()
{
	if(key == "NONE")
		return std::move(std::make_unique<BoardObjectInteractSenderNone>());
	if(key == "PUSH")
		return std::move(std::make_unique<BoardObjectInteractSenderPush>());
	if(key == "SHOOT")
		return std::move(std::make_unique<BoardObjectInteractSenderShoot>());
	if (key == "FREEZE")
		return std::move(std::make_unique<BoardObjectInteractSenderFreeze>());

	std::cout << key << " : Unfound Sender\n";

	throw key;
}

std::unique_ptr<BoardObjectInteractReceiver> BehaviourFactory::createReceiver(std::string key) throw()
{
	if (key == "NONE")
		return std::move(std::make_unique<BoardObjectInteractReceiverNone>());
	if (key == "PUSH")
		return std::move(std::make_unique<BoardObjectInteractReceiverPush>());
	if (key == "FREEZE")
		return std::move(std::make_unique<BoardObjectInteractReceiverFreeze>());

	std::cout << key << " : Unfound Receiver\n";

	throw key;
}
