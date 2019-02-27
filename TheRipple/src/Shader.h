#pragma once
#include "pch/pch.h"

class Shader
{
public:

	Shader();
	~Shader();

	void LoadShader(std::string name, GLuint type);
	void LinkShader();
	void UseShader();

	void SetUniform4f(const std::string& name, glm::fvec4 color);
	void SetUniformMat4f(const std::string& name, glm::mat4& matrix);

private:

	int GetUnifromLocation(const std::string& name);

	GLuint VerID;
	GLuint FragID;
	GLuint ShaderProg;

};

