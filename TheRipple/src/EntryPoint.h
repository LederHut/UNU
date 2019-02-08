#pragma once
#include "data.h"

class EntryPoint
{

public:

	EntryPoint();
	~EntryPoint();

	bool Run();

private:

	GLFWwindow* Window;

	std::vector<data> dv;

	void glfwinit();
	void gladinit();

};

