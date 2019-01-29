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
void Shader::Load(std::string name, GLuint type)
{

	if (type == GL_VERTEX_SHADER)
	{
		glShaderSource(VerID, 1, (const GLchar**)ReadFile(name, ".ver").c_str() , NULL);

		glCompileShader(VerID);

		GLint isCompiled = 0;
		glGetShaderiv(VerID, GL_COMPILE_STATUS, &isCompiled);
		if (!isCompiled) 
		{
			GLint logLength;
			glGetShaderiv(VerID, GL_INFO_LOG_LENGTH, &logLength);

			std::vector<GLchar> log;
			log.resize(logLength);
			glGetShaderInfoLog(VerID, logLength, &logLength, log.data());

			std::ofstream fout(std::string("FRAG") + ".log");
			fout.write(log.data(), logLength);

		}
	}
	else if (type == GL_FRAGMENT_SHADER)
	{
		glShaderSource(FragID, 1, (const GLchar**)ReadFile(name, ".frag").c_str(), NULL);

		glCompileShader(FragID);

		GLint isCompiled = 0;
		glGetShaderiv(FragID, GL_COMPILE_STATUS, &isCompiled);
		if (!isCompiled) 
		{
			GLint logLength;
			glGetShaderiv(FragID, GL_INFO_LOG_LENGTH, &logLength);

			std::vector<GLchar> log;
			log.resize(logLength);
			glGetShaderInfoLog(FragID, logLength, &logLength, log.data());

			std::ofstream fout(std::string("FRAG") + ".log");
			fout.write(log.data(), logLength);
			
		}
	}

	
}

void Shader::Link()
{
	glAttachShader(ShaderProg,VerID);
	glAttachShader(ShaderProg, FragID);

	glLinkProgram(ShaderProg);
}

void Shader::Use()
{
	glUseProgram(ShaderProg);
}

std::string Shader::ReadFile(std::string name, std::string type)
{
	std::string content;
	std::string line("");
	std::ifstream myfile;

	char errorstr[255];

	myfile.open("src\\" + name + type , std::fstream::out);
	if (myfile.bad())
	{
		std::cerr << "Error: " << strerror_s(errorstr,errno);
		
	}

	if (myfile.is_open())
	{
		while (myfile.good())
		{
			std::getline(myfile, line);
			content += "\n" + line;
		}
		myfile.close();
	}
	else
	{
		std::cout << "Unable to open file";
	}
	return content;
}
