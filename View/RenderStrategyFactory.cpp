#include "RenderStrategyFactory.h"

#include "RenderStrategies/RenderStrategyBoard.h"

RenderStrategyFactory::RenderStrategyFactory()
{
}

std::unique_ptr<RenderStrategy> RenderStrategyFactory::createStrategy(RenderStrategyKey stratKey)
{
	std::unique_ptr<RenderStrategy> newStrat = std::make_unique<RenderStrategyBoard>();

	return newStrat;
}
