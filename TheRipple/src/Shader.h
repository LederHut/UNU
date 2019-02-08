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

private:

	GLuint VerID;
	GLuint FragID;
	GLuint ShaderProg;
	
	std::string ReadFile(std::string name , std::string type);
};

