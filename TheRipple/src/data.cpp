#include "data.h"
#include "pch/pch.h"

data::data()
	:ac(0)
{
	
}

data::~data()
{

}

//Binds the created buffer.
void data::CreateVertexBuffer(GLsizei amount, std::vector<float> data)
{
	VBOs.push_back(0);
	glGenBuffers(amount, &VBOs.back());
	glBindBuffer(GL_ARRAY_BUFFER, VBOs.back());
	glBufferData(GL_ARRAY_BUFFER, data.size(), data.data(), GL_STATIC_DRAW);
}

//Binds the created array.
void data::CreateVertexArray(GLsizei amount)
{
	VAOs.push_back(0);
	glGenVertexArrays(amount, &VAOs.back());
	glBindVertexArray(VAOs.back());
}

//Adds to the current bound buffer.
void data::AddAttribPointer(GLint size, GLuint type, GLboolean normalized,GLsizei stride,const void* pointer )
{
	glEnableVertexAttribArray(ac);
	glVertexAttribPointer(ac, size, type, normalized, stride, pointer);
	ac++;
}

void data::Bind(GLuint type, GLuint index)
{
	if (type == GL_ARRAY_BUFFER)
	{
		glBindBuffer(type, VBOs[index]);
	}
	else if (type == GL_VERTEX_ARRAY)
	{
		glBindBuffer(type, VAOs[index]);
	}
	else if (type == GL_ELEMENT_ARRAY_BUFFER)
	{
		glBindBuffer(type, EBOs[index]);
	}
}

void data::UnBind()
{

	//Not in use right now.

}