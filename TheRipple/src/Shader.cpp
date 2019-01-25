#include "Shader.h"
#include "pch/pch.h"

Shader::Shader()
{
}

Shader::~Shader()
{
}

void Shader::LoadShader(std::string name)
{

	

}

std::string Shader::ReadFile(std::string name)
{
	std::string content;
	std::string line("");
	std::ifstream myfile;

	char errorstr[255];

	myfile.open("src\\" + name, std::fstream::out);
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
