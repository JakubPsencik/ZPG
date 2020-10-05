#pragma once

#include <iostream>
#include <GLFW\glfw3.h>

class Application
{

	private:
	
		/*stored instance*/
		static Application* _instance;

		void error_callback(int error, const char* description);
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		void window_focus_callback(GLFWwindow* window, int focused);
		void window_iconify_callback(GLFWwindow* window, int iconified);
		void window_size_callback(GLFWwindow* window, int width, int height);
		void cursor_callback(GLFWwindow* window, double x, double y);
		void button_callback(GLFWwindow* window, int button, int action, int mode);

	protected:
		/*private constructor to prevent instancing*/
		Application();
		/*descructor*/
		~Application();

	public:

		/*static access method*/
		static Application* getInstance();

		static void appSetErrorCallback(int error, const char* description);
		static void appSetKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void appSetCursorPosCallback(GLFWwindow* window, double mouseXPos, double mouseYPos);
		static void appSetMouseButtonCallback(GLFWwindow* window, int button, int action, int mode);
		static void appSetWindowFocusCallback(GLFWwindow* window, int focused);
		static void appSetWindowIconifyCallback(GLFWwindow* window, int iconified);
		static void appSetWindowSizeCallback(GLFWwindow* window, int width, int height);
};

