#ifndef I_RENDER_STRATEGY_FACTORY_H
#define I_RENDER_STRATEGY_FACTORY_H

#include <memory>

#include "RenderStrategies/RenderStrategy.h"

enum class RenderStrategyKey
{
	RENDER_STRATEGY_BOARD,
	RENDER_STRATEGY_PAUSE
};

class IRenderStrategyFactory
{
public:
	IRenderStrategyFactory();

	virtual std::unique_ptr<RenderStrategy> createStrategy(RenderStrategyKey stratKey) = 0;
	virtual std::unique_ptr<RenderStrategy> createStrategy(std::string key) = 0;

};

#endif