#include "InputStateBoard.h"

#include "../../View/IView.h"

InputStateBoard::InputStateBoard()
	: InputState(), buttonDown(false)
{
}

void InputStateBoard::handle(IGameModel& model, IView& view)
{
	GLFWwindow* window = view.getWindow();

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		model.move(Point(0, 1));
		return;
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		model.move(Point(1, 0));
		return;
	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		model.move(Point(0, -1));
		return;
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		model.move(Point(-1, 0));
		return;
	}

	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
	{
		if (!buttonDown)
		{
			model.change(false);
			buttonDown = true;
		}
		return;
	}

	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		if (!buttonDown)
		{
			model.change(true);
			buttonDown = true;
		}
		return;
	}

	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
	{
		if (!buttonDown)
		{
			model.reloadCurrentLevel();
			buttonDown = true;
		}
		return;
	}
	
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		if (!buttonDown)
		{
			model.interact();
			buttonDown = true;
		}
		return;
	}

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		if (!buttonDown)
		{
			model.changeMenu(true);
			buttonDown = true;
		}
		return;
	}

	buttonDown = false;
}
