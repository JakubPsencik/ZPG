#pragma once
#include "VertexShader.h"

VertexShader::VertexShader() 
{
	ID_ = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(ID_, 1, &vertex_shader, NULL);
	glCompileShader(ID_);
}

void VertexShader::Attach(GLuint shaderId)
{
	glAttachShader(shaderId, ID_);
}