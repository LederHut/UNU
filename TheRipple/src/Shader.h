#pragma once
#include "pch/pch.h"

class Shader
{
public:

	Shader();
	~Shader();

private:

	void LoadShader(std::string name);
	std::string ReadFile(std::string name);
};

