#include "RenderStrategyBoard.h"

RenderStrategyBoard::RenderStrategyBoard()
	: RenderStrategy()
{
}

void RenderStrategyBoard::execute(GLFWwindow* window, Camera& camera, unsigned const int width, unsigned const int height)
{
	drawFPS(window);
	clearScreen();
	//camera->Inputs(window);
	updateCamera(camera);
	drawScene(camera);

	// Swap the back buffer with the front buffer
	glfwSwapBuffers(window);
	// Take care of all GLFW events
	glfwPollEvents();
}

void RenderStrategyBoard::drawFPS(GLFWwindow* window)
{
	// Updates counter and times
	crntTime = glfwGetTime();
	timeDiff = crntTime - prevTime;
	counter++;

	if (timeDiff >= 1.0 / 30.0)
	{
		// Creates new title
		std::string FPS = std::to_string((int)((1.0 / timeDiff) * counter));
		std::string newTitle = "Sudsy HD - " + FPS + " FPS";
		glfwSetWindowTitle(window, newTitle.c_str());

		// Resets times and counter
		prevTime = crntTime;
		counter = 0;
	}
}

void RenderStrategyBoard::clearScreen()
{
	// Specify the color of the background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// Clean the back buffer and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderStrategyBoard::updateCamera(Camera& camera)
{
	// Updates and exports the camera matrix to the Vertex Shader
	camera.updateMatrix(45.0f, 0.1f, 100.0f);
}

void RenderStrategyBoard::drawScene(const Camera& camera)
{
}
