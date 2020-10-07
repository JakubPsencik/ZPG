#pragma once
#include "OpenGL_libraries.h"

//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>
#include "Application.h"


class FragmentShader
{

private:
	const char* fragment_shader =
		"#version 330\n"
		"out vec4 frag_colour;"
		"void main () {"
		" frag_colour = vec4 (0.5, 0.0, 0.5, 1.0);"
		"}";

	GLuint ID_;

public:

	FragmentShader();	
	void Attach(GLuint shaderId_);
};

