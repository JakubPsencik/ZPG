#include "OpenGL_libraries.h"
#include "Shader.h"
#include "VertexShader.h"
#include "FragmentShader.h"

Shader::Shader()
{
	// Create and compile shaders
	programID_ = glCreateProgram();

	vertexShader_ = VertexShader();
	fragmentShader_ = FragmentShader();
	vertexShader_.Attach(programID_);
	fragmentShader_.Attach(programID_);
	glLinkProgram(programID_);

	modelMatrix_ = glGetUniformLocation(programID_, "modelMatrix");

	GLint status;
	glGetProgramiv(programID_, GL_LINK_STATUS, &status);

	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(programID_, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(programID_, infoLogLength, NULL, strInfoLog);
		std::cerr << "Linker failure: %s\n" << strInfoLog << std::endl;
		delete[] strInfoLog;
		exit(-1);
	}
}

void Shader::sendUniform(const GLchar* name, glm::vec4 data)
{
	GLint uniform_id = glGetUniformLocation(programID_, name);

	if (uniform_id >= 0) {
		glUniform4f(uniform_id, data.x, data.y, data.z, data.w);
	}
	else {
		// in shader doesn't exist uniform variable
		std::cerr << "Error: in shader uniform variable doesn't exist" << std::endl;
		exit(-1);
	}
}

void Shader::sendUniform(const GLchar* name, glm::mat4 data)
{
	GLint uniform_id = glGetUniformLocation(programID_, name);

	if (uniform_id >= 0) {
		glUniformMatrix4fv(uniform_id,1, GL_FALSE, &data[0][0]);
	}
	else {
		// in shader doesn't exist uniform variable
		std::cerr << "Error: in shader uniform variable doesn't exist" << std::endl;
		exit(-1);
	}
}

void Shader::UseShader()
{
	glUseProgram(programID_);
}
