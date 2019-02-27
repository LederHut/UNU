#pragma once
#include "pch/pch.h"
#include "Shader.h"

class data :
	public Shader
{
public:

	data();
	~data();

	void CreateVertexBuffer(GLsizei amount, GLsizei size, std::vector<float> data, GLuint usage);
	void CreateVertexBuffer(GLsizei amount, GLsizei size, void* data, GLuint usage);

	void CreateVertexArray(GLsizei amount);

	void AddAttribPointer(GLint size, GLuint type, GLboolean normalized, GLsizei stride, const void* pointer);

	void Bind(GLuint type, GLuint index);
	void UnBind(GLuint type);

private:

	std::vector<GLuint> VBOs;
	std::vector<GLuint> VAOs;
	std::vector<GLuint> EBOs;

	GLuint ac; //Attrib pointer counter

};

