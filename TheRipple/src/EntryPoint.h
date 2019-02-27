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

	Particle* p;

	double mousex, mousey;
	int releasd;

	void glfwinit();
	void gladinit();

	void input();

};

