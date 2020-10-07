#pragma once
#include "OpenGL_libraries.h"

//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>
#include "VertexShader.h"
#include "FragmentShader.h"

class Shader
{
private:

	GLuint programID_;
	GLint modelMatrix_;

	VertexShader vertexShader_;
	FragmentShader fragmentShader_;
public: 

	Shader();

	//GLchar* name - name of nevim ceho
	void sendUniform(const GLchar* name, glm::vec4 data);
	void sendUniform(const GLchar* name, glm::mat4 data);

	void UseShader();
};

