#include "pch/pch.h"
#include "EntryPoint.h"


EntryPoint::EntryPoint():
	Window(nullptr)
{
	glfwinit();
	gladinit();
}

EntryPoint::~EntryPoint()
{
	glfwTerminate();
}

bool EntryPoint::Run()
{
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(Window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(Window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	return 0;
}

void EntryPoint::glfwinit()
{
	/* Initialize the library */
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	Window = glfwCreateWindow(640, 480, "The-Ripple", NULL, NULL);
	if (!Window)
	{
		glfwTerminate();
		std::cout << "BREAK" << std::endl;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(Window);
}

void EntryPoint::gladinit()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}
}
