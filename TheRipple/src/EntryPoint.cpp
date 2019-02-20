#include "pch/pch.h"
#include "EntryPoint.h"



EntryPoint::EntryPoint() :
	Window(nullptr),
	mousex(0),
	mousey(0),
	releasd(1)
{
	glfwinit();
	gladinit();

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	Particle p(TR_NONE, 1.0f);
	
	dv.push_back(p);
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
		input();
		
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		//draw our first triangle
		dv[0].UseShader();
		dv[0].Bind(GL_VERTEX_ARRAY ,0);
		// for some reason there is a point in the middle don't know why
		glDrawArrays(GL_POINTS, 0, 359);

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

	glfwSetInputMode(Window, GLFW_STICKY_MOUSE_BUTTONS, 1);
}

void EntryPoint::gladinit()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}
}

void EntryPoint::input()
{
	if (glfwGetMouseButton(Window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		if(releasd)
		{
			glfwGetCursorPos(Window, &mousex, &mousey);
			releasd = 0;
		}
		
	}
	else if (glfwGetMouseButton(Window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
	{
		if (!releasd)
		{
			glfwGetCursorPos(Window, &mousex, &mousey);
			releasd = 1;
		}
	}
}
