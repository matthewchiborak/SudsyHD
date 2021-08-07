#ifndef RENDER_STRATEGY_FACTORY_H
#define RENDER_STRATEGY_FACTORY_H

#include "IRenderStrategyFactory.h"

class RenderStrategyFactory: public IRenderStrategyFactory
{
public:
	RenderStrategyFactory();

	std::unique_ptr<RenderStrategy> createStrategy(RenderStrategyKey stratKey) override;

};

#endif