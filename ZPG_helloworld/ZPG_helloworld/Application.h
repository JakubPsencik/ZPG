#pragma once
#include "OpenGL_libraries.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
/*#include "Object.h"
#include "Shader.h"*/
/*#include "VertexShader.h"
#include "FragmentShader.h"*/

class Application
{
	private:		
		/*stored instance*/
		static Application* instance_;

		GLFWwindow *window_;
		int width_;
		int height_;

		GLuint shaderProgram_;

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

		// Singletons should not be cloneable.
		Application(Application& other) = delete;
		// Singletons should not be assignable.
		void operator = (Application& other) = delete;
		/*static access method*/
		static Application* getInstance();
		void appSetGLFWCallbacks();
		void appSetErrorCallback();
		void run();
		void resize(glm::mat4 *Matrix, float points[], float scale, bool increasing);
};

