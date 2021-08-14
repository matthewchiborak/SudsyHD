#ifndef I_BEHAVIOUR_FACTORY_H
#define I_BEHAVIOUR_FACTORY_H

#include <memory>
#include <string>

#include "BoardObjectBehaviours/BoardObjectBehaviour.h"
#include "BoardObjectInteractSenders/BoardObjectInteractSender.h"
#include "BoardObjectInteractReceivers/BoardObjectInteractReceiver.h"

class IBehaviourFactory
{
public:
	IBehaviourFactory();

	virtual std::unique_ptr<BoardObjectBehaviour> createBehaviour(std::string key) throw() = 0;
	virtual std::unique_ptr<BoardObjectInteractSender> createSender(std::string key) throw() = 0;
	virtual std::unique_ptr<BoardObjectInteractReceiver> createReceiver(std::string key) throw() = 0;

};

#endif