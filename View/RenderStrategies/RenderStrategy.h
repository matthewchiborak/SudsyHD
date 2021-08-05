#ifndef RENDER_STRATEGY_H
#define RENDER_STRATEGY_H

class RenderStrategy
{
public:
	RenderStrategy();

	virtual void execute() = 0;
};

#endif