#pragma once
#include "Application.h"
#include "VertexShader.h"
#include "FragmentShader.h"
#include "Object.h"
#include "Shader.h"

using namespace std;

Application* Application::instance_ = NULL;

Application* Application::getInstance()
{
	if (instance_ == 0) {
		instance_ = new Application();
	}

	return instance_;
}

/*constructor*/
Application::Application()
{
	appSetErrorCallback();

	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(EXIT_FAILURE);
	}
	window_ = glfwCreateWindow(800, 600, "ZPG", NULL, NULL);

	if (!window_)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window_);
	glfwSwapInterval(1);

	//SET CALLBACKS
	appSetGLFWCallbacks();
	
	// start GLEW extension handler
	glewExperimental = GL_TRUE;

	int res = glewInit();

	if (res != 0) {

		fprintf(stderr, "ERROR: glewInit error occured\n");
		exit(EXIT_FAILURE);		
	}

	// get version info
	printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
	printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
	printf("Vendor %s\n", glGetString(GL_VENDOR));
	printf("Renderer %s\n", glGetString(GL_RENDERER));
	printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));

	int major, minor, revision;
	glfwGetVersion(&major, &minor, &revision);
	printf("Using GLFW %i.%i.%i\n", major, minor, revision);
	printf("----------------------------------------------\n");

	int width, height;
	glfwGetFramebufferSize(window_, &width, &height);
	float ratio = width / (float)height;
	glViewport(0, 0, width, height);


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);

	VertexShader vertexShader_ = VertexShader();
	FragmentShader fragmentShader_ = FragmentShader();
	Shader shader_ = Shader();
}

/*descructor*/
Application::~Application() 
{
	glfwDestroyWindow(window_);
	glfwTerminate();
}

void Application::error_callback(int error, const char* description)
{
	/*Writes the occurred error with its description to the console*/
	cerr << "error" << " [" << error << " ]: " << description << endl;
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
	width_ = width;
	height_ = height;
	printf("resize %d, %d \n", width, height);
	/*sets size(shape) of a window, in which will the scene be drawn*/
	glViewport(0, 0, width_, height_);
}

void Application::cursor_callback(GLFWwindow* window, double x, double y)
{
	printf("cursor_callback %d, %d\n", (int)x, (int)y);
}

void Application::button_callback(GLFWwindow* window, int button, int action, int mode)
{
	printf("button_callback [%d,%d,%d]\n", button, action, mode);
}

void Application::appSetGLFWCallbacks()
{

	glfwSetKeyCallback(

		window_, 
		[](GLFWwindow* window, int key, int scancode, int action, int mods) -> void
		{
			Application::getInstance()->key_callback(window, key, scancode, action, mods);
		});

	glfwSetWindowFocusCallback(
		window_,
		[](GLFWwindow* window, int focused) -> void
		{
			Application::getInstance()->window_focus_callback(window, focused);
		}
		);

	glfwSetWindowIconifyCallback(
		window_,
		[](GLFWwindow* window, int iconified) -> void
		{
			Application::getInstance()->window_iconify_callback(window, iconified);
		}
		);
	
	glfwSetWindowSizeCallback(
		window_,
		[](GLFWwindow* window, int width, int height) -> void
		{
			Application::getInstance()->window_size_callback(window, width, height);
		}
		);

	glfwSetCursorPosCallback(
		window_,
		[](GLFWwindow* window, double x, double y) -> void
		{
			Application::getInstance()->cursor_callback(window, x, y);
		});


	glfwSetMouseButtonCallback(
		window_,
		[](GLFWwindow* window, int button, int action, int mode) -> void
		{
			Application::getInstance()->button_callback(window, button, action, mode);
		}
		);
}

void Application::appSetErrorCallback()
{

	glfwSetErrorCallback(
		[](int error, const char* description) -> void
		{
			Application::getInstance()->error_callback(error, description);
		}
		);
}

void Application::run()
{

	float points[] = {
	-0.25f, 0.25f, 0.0f,
	0.25f, 0.25f, 0.0f,
	0.25f, -0.25f, 0.0f,
	-0.25f, -0.25f, 0.0f,
	};

	Object object_ = Object(points, sizeof(points));
	Shader shader_ = Shader();

	//modelova matice - 4 rozmerna
	glm::mat4 M = glm::mat4(1.0f);
	
	/*M = glm::rotate(M, angle, glm::vec3(1.0f, 0.0f, 0.0f));
	M = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	*/	/*M = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	*/			
	//M = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -0.5f, 0.0f));
	
	float scale = 0.0f;
	bool increasing = true;

	while (!glfwWindowShouldClose(window_))
	{		
		//resize(&M, points, scale, increasing);
		if (scale < 0.75f && increasing) {
			scale += 0.005f;
		}
		if ((scale >= 0.75f) && increasing) {
			increasing = false;
		}
		if (scale > -0.75f && !increasing) {
			scale -= 0.005f;
		}
		if ((scale <= -0.75f) && !increasing) {
			increasing = true;
		}

		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shaderProgram_);

		//M = glm::scale(glm::mat4(1.0f), glm::vec3(scale));
		//M = glm::translate(glm::mat4(1.0f), glm::vec3(0.f, scale, 0.0f));
		M = glm::rotate(M, glm::radians(0.5f), glm::vec3(0.0f, 0.0f, 1.0f));

		//Render
		shader_.UseShader();
		shader_.sendUniform("modelMatrix", M);
		object_.BindVertexArray();
		//location, count, transpose, *value

		// update other events like input handling
		glfwPollEvents();

		// draw object
		glDrawArrays(GL_POLYGON, 0, 4); //mode,first,count

		// put the stuff we’ve been drawing onto the display
		glfwSwapBuffers(window_);
	}
}

void Application::resize(glm::mat4* Matrix, float points[], float scale, bool increasing)
{
	Object object_ = Object(points, sizeof(points));
	Shader shader_ = Shader();

	if (scale < 0.75f && increasing) {
		scale += 0.005f;
	}
	if ((scale >= 0.75f) && increasing) {
		increasing = false;
	}
	if (scale > 0.0f && !increasing) {
		scale -= 0.005f;
	}
	if ((scale <= 0.0f) && !increasing) {
		increasing = true;
	}

	// clear color and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(shaderProgram_);

	*Matrix = glm::scale(glm::mat4(1.0f), glm::vec3(scale));

	//Render
	shader_.UseShader();
	shader_.sendUniform("modelMatrix", *Matrix);
	object_.BindVertexArray();
	//location, count, transpose, *value

	// update other events like input handling
	glfwPollEvents();

	// draw object
	glDrawArrays(GL_POLYGON, 0, 4); //mode,first,count

	// put the stuff we’ve been drawing onto the display
	glfwSwapBuffers(window_);

}

