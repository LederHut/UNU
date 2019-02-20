#pragma once
#include "Particle.h"

class EntryPoint
{

public:

	EntryPoint();
	~EntryPoint();

	bool Run();

private:

	GLFWwindow* Window;

	std::vector<data> dv;

	double mousex, mousey;
	int releasd;

	void glfwinit();
	void gladinit();

	void input();

};

