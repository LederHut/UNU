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

	glm::fvec3 Pressed;
	glm::fvec3 Releasd;

	int releasd;
	int brushed;

	void glfwinit();
	void gladinit();

	void input();

};

