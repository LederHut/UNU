#include "Shader.h"
#include "pch/pch.h"

Shader::Shader()
{
	VerID = glCreateShader(GL_VERTEX_SHADER);
	FragID = glCreateShader(GL_FRAGMENT_SHADER);
	ShaderProg = glCreateProgram();
}

Shader::~Shader()
{
}

//Loads and Compiles Shader
void Shader::LoadShader(std::string name, GLuint type)
{
	GLint success;
	GLchar infoLog[512];

	if (type == GL_VERTEX_SHADER)
	{
		//last time I was here
		std::ifstream fin("src\\shader\\" + name + ".ver");
		std::stringstream buff;
		buff << fin.rdbuf();
		const std::string str = buff.str();
		const char* src = str.c_str();

		GLCall(glShaderSource(VerID, 1, (const GLchar**)&src, NULL));

		GLCall(glCompileShader(VerID));

		glGetShaderiv(VerID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(FragID, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
	}
	else if (type == GL_FRAGMENT_SHADER)
	{
		std::ifstream fin("src\\shader\\" + name + ".frag");
		std::stringstream buff;
		buff << fin.rdbuf();
		const std::string str = buff.str();
		const char* src = str.c_str();

		GLCall(glShaderSource(FragID, 1, (const GLchar**)&src, NULL));

		GLCall(glCompileShader(FragID));

		glGetShaderiv(FragID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(FragID, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
	}
}

void Shader::LinkShader()
{
	glAttachShader(ShaderProg, VerID);
	glAttachShader(ShaderProg, FragID);

	glLinkProgram(ShaderProg);

	glDeleteShader(VerID);
	glDeleteShader(FragID);
}

void Shader::UseShader()
{
	GLCall(glUseProgram(ShaderProg));
}

std::string Shader::ReadFile(std::string name, std::string type)
{
	

	return std::string();
}
