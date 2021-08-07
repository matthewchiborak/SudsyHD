#include "View.h"

#include "RenderStrategies/RenderStrategyBoard.h"

View::View(Point windowSize, IGameModel& model, IRenderStrategyFactory& renderStratFactory, ISpriteFlyweightFactory& spriteFactory, std::string shaderFilePath)
	: IView(windowSize, model, renderStratFactory, spriteFactory), shaderFilePath(shaderFilePath)
{
	setUp();
	this->renderStrategy = this->renderStratFactory->createStrategy(RenderStrategyKey::RENDER_STRATEGY_BOARD);
}

View::~View()
{
}

void View::draw()
{
	if (cutoutShader == nullptr)
		createShader();
	
	renderStrategy->execute(*this);
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
	setUpWindow();
	createWindow();
	configureWindow();
	createCamera();
}

void View::setUpWindow()
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

}

void View::createWindow()
{
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
}

void View::configureWindow()
{
	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	glViewport(0, 0, windowSize.getX(), windowSize.getY());

	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

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
}

void View::createCamera()
{
	// Creates camera object
	camera = Camera(windowSize.getX(), windowSize.getY(), glm::vec3(0.0f, 1.2f, 0.0f));
	camera.setRotation(90.0f, 0.0f);
}

void View::createShader()
{
	this->cutoutShader = new Shader((shaderFilePath + "/default.vert").c_str(), (shaderFilePath + "/cutout.frag").c_str(), (shaderFilePath + "/default.geom").c_str());

	this->cutoutShader->Activate();
	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3  lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);
	glUniform4f(glGetUniformLocation(cutoutShader->ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(cutoutShader->ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
}
