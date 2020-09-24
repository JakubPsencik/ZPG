#include "Application.h"


Application* Application::_instance = NULL;

Application* Application::getInstance()
{
	if (_instance == 0) {
		_instance = new Application();
	}

	return _instance;
}

/*constructor*/
Application::Application()
{

}

/*descructor*/
Application::~Application() 
{

}

void Application::error_callback(int error, const char* description)
{
	/*Writes the C string pointed by str to the stream.*/
	fputs(description, stderr);
}

void Application::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
}

void Application::window_focus_callback(GLFWwindow* window, int focused)
{
	printf("window_focus_callback \n");
}

void Application::window_iconify_callback(GLFWwindow* window, int iconified)
{
	printf("window_iconify_callback \n");
}

void Application::window_size_callback(GLFWwindow* window, int width, int height)
{
	printf("resize %d, %d \n", width, height);
	/*sets size(shape) of a window, in which will the scene be drawn*/
	glViewport(0, 0, width, height);
}

void Application::cursor_callback(GLFWwindow* window, double x, double y)
{
	printf("cursor_callback %d, %d\n", (int)x, (int)y);
}

void Application::button_callback(GLFWwindow* window, int button, int action, int mode)
{
	if (action == GLFW_PRESS) printf("button_callback [%d,%d,%d]\n", button, action, mode);
}

/*
- Returns the currently connected monitors
*/
void Application::appSetErrorCallback(int error, const char* description)
{
	Application::getInstance()->error_callback(error, description);
}

/*
- sets the key callback of the specified window
- called when a key is pressed, repeated or released.
*/
void Application::appSetKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Application::getInstance()->key_callback(window, key, scancode, action, mods);
}

/*
- sets the cursor position callback of the specified window
- called when the cursor is moved
*/
void Application::appSetCursorPosCallback(GLFWwindow* window, double mouseXPos, double mouseYPos)
{
	Application::getInstance()->cursor_callback(window, mouseXPos, mouseYPos);
}

/*
- sets the mouse button callback of the specified window
- called when a mouse button is pressed or released.
*/
void Application::appSetMouseButtonCallback(GLFWwindow* window, int button, int action, int mode)
{
	Application::getInstance()->button_callback(window, button, action, mode);
}

/*
- sets the focus callback of the specified window
- called when the window gains or loses input focus
*/
void Application::appSetWindowFocusCallback(GLFWwindow* window, int focused)
{
	Application::getInstance()->window_focus_callback(window, focused);
}

/*
- sets the iconification callback of the specified window
- called when the window is iconified or restored.
*/
void Application::appSetWindowIconifyCallback(GLFWwindow* window, int iconified)
{
	Application::getInstance()->window_iconify_callback(window, iconified);
}

/*
- sets the close callback of the specified window
- called when the user attempts to close the window
*/
void Application::appSetWindowSizeCallback(GLFWwindow* window, int width, int height)
{
	Application::getInstance()->window_size_callback(window, width, height);
}

