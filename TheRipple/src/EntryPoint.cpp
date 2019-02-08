#include "pch/pch.h"
#include "EntryPoint.h"


EntryPoint::EntryPoint():
	Window(nullptr)
{
	glfwinit();
	gladinit();

	glClearColor(1.0f, 0.3f, 0.3f, 1.0f);

	data test;

	std::vector<float> vertices = {
		-0.5f, -0.5f, 0.0f, // left  
		 0.5f, -0.5f, 0.0f, // right 
		 0.0f,  0.5f, 0.0f  // top   
	};

	test.CreateVertexArray(1);
	test.CreateVertexBuffer(1, vertices);

	test.AddAttribPointer(3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	test.LoadShader(std::string("VShader"), GL_VERTEX_SHADER);
	test.LoadShader(std::string("FShader"), GL_FRAGMENT_SHADER);

	test.LinkShader();

	dv.push_back(test);
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
		

		//draw our first triangle
		dv[0].UseShader();
		dv[0].Bind(GL_VERTEX_ARRAY ,0);
		glDrawArrays(GL_TRIANGLES, 0, 3);

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
