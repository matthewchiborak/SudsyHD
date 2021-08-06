#include "View.h"

#include "RenderStrategies/RenderStrategyBoard.h"

View::View(Point windowSize, IGameModel& model)
	: IView(windowSize, model)
{
	setUp();
	this->renderStrategy = new RenderStrategyBoard();
}

void View::draw()
{
	renderStrategy->execute(window, camera, windowSize.getX(), windowSize.getY());
}

void View::clearMemory()
{
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
}

void View::setUp()
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Only use this if you don't have a framebuffer
	glfwWindowHint(GLFW_SAMPLES, 8);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object
	window = glfwCreateWindow(windowSize.getX(), windowSize.getY(), "Sudsy HD", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, windowSize.getX(), windowSize.getY());

	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	//Gamma correction
	//glEnable(GL_FRAMEBUFFER_SRGB);

	// Enables Multisampling
	glEnable(GL_MULTISAMPLE);

	// Enables Cull Facing
	glEnable(GL_CULL_FACE);
	// Keeps front faces
	glCullFace(GL_FRONT);
	// Uses counter clock-wise standard
	glFrontFace(GL_CCW);
	// Configures the blending function
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Creates camera object
	camera = Camera(windowSize.getX(), windowSize.getY(), glm::vec3(0.8f, 1.2f, 0.5f));
	camera.setRotation(50.0f, 0.0f);
}
