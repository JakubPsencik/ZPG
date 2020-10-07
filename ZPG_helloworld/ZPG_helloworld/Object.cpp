#include "Object.h"
#include "Application.h"
Object::Object(float* points, int length)
{
	//vertex buffer object (VBO)
	glGenBuffers(1, &VBO_); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO_);
	glBufferData(GL_ARRAY_BUFFER, length, points, GL_STATIC_DRAW);

	//vertex attribute object(VAO)
	glGenVertexArrays(1, &VAO_); //generate the VAO
	glBindVertexArray(VAO_); //bind the VAO
	glEnableVertexAttribArray(0); //enable vertex attributes
	glBindBuffer(GL_ARRAY_BUFFER, VBO_);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}

void Object::BindVertexArray()
{
	glBindVertexArray(VAO_);
}
