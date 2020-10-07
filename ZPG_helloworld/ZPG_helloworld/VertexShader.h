#pragma once
#include "OpenGL_libraries.h"

//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>
#include "Application.h"


class VertexShader
{

private:
	const char* vertex_shader = "#version 330\n"
		"uniform mat4 modelMatrix;"
		"layout(location=0) in vec3 vp;"
		"void main () {"
		" gl_Position = modelMatrix * vec4 (vp, 1.0);"
		"}";

	GLuint ID_;

public:

	VertexShader();
	void Attach(GLuint shaderId_);
};

