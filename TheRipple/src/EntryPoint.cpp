#include "pch/pch.h"
#include "EntryPoint.h"

#define SCREEN_WITDH 800.0f
#define SCREEN_HEIGTH 600.0f

EntryPoint::EntryPoint() :
	Window(nullptr),
	p(nullptr),
	releasd(1),
	brushed(),
	Releasd(-1.0f, -1.0f, 0.0f),
	Pressed(-1.0f, -1.0f, 0.0f)
{
	glfwinit();
	gladinit();

	p = new Particle();

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

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

		p->UseShader();
		p->Bind(GL_VERTEX_ARRAY, 0);

		//glm::mat4 model(1.0f);
		glm::mat4 projection(1.0f);
		glm::mat4 view(1.0f);
		
		//model = glm::rotate(model, glm::radians(180.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -1.0f));
		projection = glm::ortho(0.0f, SCREEN_WITDH, SCREEN_HEIGTH, 0.0f, 0.1f, 100.0f);

		//p->SetUniformMat4f("u_Model", model);
		p->SetUniformMat4f("u_Proj", projection);
		p->SetUniformMat4f("u_View", view);
		//p->SetUniform4f("u_Gravity",);
		
		glDrawArrays(GL_POINTS, 0, p->Amount());

		input();
		if (!brushed && !releasd)
		{
			p->Brush(Pressed, 20.0f);
			brushed = 1;
		}
		p->Update();

		/* Swap front and back buffers */
		glfwSwapBuffers(Window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	delete p;

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
	Window = glfwCreateWindow(SCREEN_WITDH, SCREEN_HEIGTH, "The-Ripple", NULL, NULL);
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
	if (glfwGetMouseButton(Window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && releasd)
	{
		double mousex(0), mousey(0);
		glfwGetCursorPos(Window, &mousex, &mousey);
		releasd = 0;
		std::cout << mousex << ", " << mousey << ": " << releasd << std::endl;
		Pressed = glm::fvec3(mousex, mousey, 0.0f);
	}
	else if (glfwGetMouseButton(Window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE && !releasd)
	{
		double mousex(0), mousey(0);
		glfwGetCursorPos(Window, &mousex, &mousey);
		releasd = 1;
		brushed = 0;
		//std::cout << mousex << ", " << mousey << ": " << releasd << std::endl;
		Releasd = glm::fvec3(mousex, mousey, 0.0f);
	}
}
