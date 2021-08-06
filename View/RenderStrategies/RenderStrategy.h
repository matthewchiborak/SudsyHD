#ifndef RENDER_STRATEGY_H
#define RENDER_STRATEGY_H

#include "../Core/Mesh.h"

class RenderStrategy
{
public:
	RenderStrategy();

	virtual void execute(GLFWwindow* window, Camera& camera, unsigned const int width, unsigned const int height) = 0;
};

#endif