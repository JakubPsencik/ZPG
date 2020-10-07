#pragma once
#include "OpenGL_libraries.h"

class Object
{

public:

	Object(float* points, int length);
	void BindVertexArray();

private:
	
	//vertex attribute object(VAO)
	GLuint VAO_ = 0;
	//vertex buffer object(VBO)
	GLuint VBO_ = 0;


};

