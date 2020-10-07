#include "FragmentShader.h"

FragmentShader::FragmentShader() {

	ID_ = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(ID_, 1, &fragment_shader, NULL);
	glCompileShader(ID_);
}

void FragmentShader::Attach(GLuint shaderId)
{	
	glAttachShader(shaderId, ID_);
}