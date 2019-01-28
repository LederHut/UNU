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

	void glfwinit();
	void gladinit();

};

