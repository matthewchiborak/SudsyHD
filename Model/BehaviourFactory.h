#ifndef BEHAVIOUR_FACTORY_H
#define BEHAVIOUR_FACTORY_H

#include "IBehaviourFactory.h"

class BehaviourFactory: public IBehaviourFactory
{
public:
	BehaviourFactory();

	std::unique_ptr<BoardObjectBehaviour> createBehaviour(std::string key) throw();
	std::unique_ptr<BoardObjectInteractSender> createSender(std::string key) throw();
	std::unique_ptr<BoardObjectInteractReceiver> createReceiver(std::string key) throw();
};

#endif