#include "RenderStrategyFactory.h"

#include "RenderStrategies/RenderStrategyBoard.h"
#include "RenderStrategies/RenderStrategyPause.h"
#include "RenderStrategies/RenderStrategyEnd.h"
#include "RenderStrategies/RenderStrategyWin.h"
#include "RenderStrategies/RenderStrategyGameOver.h"

RenderStrategyFactory::RenderStrategyFactory()
{
}

std::unique_ptr<RenderStrategy> RenderStrategyFactory::createStrategy(RenderStrategyKey stratKey)
{
	if (stratKey == RenderStrategyKey::RENDER_STRATEGY_BOARD)
	{
		std::unique_ptr<RenderStrategy> newStrat = std::make_unique<RenderStrategyBoard>();
		return newStrat;
	}

	if (stratKey == RenderStrategyKey::RENDER_STRATEGY_PAUSE)
	{
		std::unique_ptr<RenderStrategy> newStrat = std::make_unique<RenderStrategyPause>();
		return newStrat;
	}
}

std::unique_ptr<RenderStrategy> RenderStrategyFactory::createStrategy(std::string key)
{
	if (key == "Board")
	{
		std::unique_ptr<RenderStrategy> newStrat = std::make_unique<RenderStrategyBoard>();
		return newStrat;
	}

	if (key == "Pause")
	{
		std::unique_ptr<RenderStrategy> newStrat = std::make_unique<RenderStrategyPause>();
		return newStrat;
	}

	if (key == "End")
	{
		std::unique_ptr<RenderStrategy> newStrat = std::make_unique<RenderStrategyEnd>();
		return newStrat;
	}

	if (key == "Win")
	{
		std::unique_ptr<RenderStrategy> newStrat = std::make_unique<RenderStrategyWin>();
		return newStrat;
	}

	if (key == "GameOver")
	{
		std::unique_ptr<RenderStrategy> newStrat = std::make_unique<RenderStrategyGameOver>();
		return newStrat;
	}
}
