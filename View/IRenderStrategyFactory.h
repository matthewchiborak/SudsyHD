#ifndef I_RENDER_STRATEGY_FACTORY_H
#define I_RENDER_STRATEGY_FACTORY_H

#include <memory>

#include "RenderStrategies/RenderStrategy.h"

enum class RenderStrategyKey
{
	RENDER_STRATEGY_BOARD
};

class IRenderStrategyFactory
{
public:
	IRenderStrategyFactory();

	virtual std::unique_ptr<RenderStrategy> createStrategy(RenderStrategyKey stratKey) = 0;

};

#endif