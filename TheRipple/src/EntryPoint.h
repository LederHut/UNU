#pragma once

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

