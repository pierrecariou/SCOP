/*************************************************************
 * File              : Window.cpp
 * Author            : Pierre Cariou <pierrecariou@outlook.fr>
 * Date              : 15.07.2022
 * Last Modified Date: 15.07.2022
 * Last Modified By  : Pierre Cariou <pierrecariou@outlook.fr>
 *************************************************************/

#include <Window.hpp>

Window::Window()
{
	std::cout << "window created" << std::endl;
	initialize();
	create();
	//draw();
}

Window::~Window()
{
	glfwTerminate();
}

void	Window::initialize()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);	
}

void	Window::create()
{
	window = glfwCreateWindow(800, 600, "SCOP", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);

	// setup glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return ;
	}
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//	glfwSetKeyCallback(window, KeyCallBack);
}

void	Window::draw(unsigned int shaderProgramId, unsigned int VAOId)
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glUseProgram(shaderProgramId);
	glBindVertexArray(VAOId);
	while(!glfwWindowShouldClose(window))
	{
		processInput();
		// rendering commands
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();    
	}
}

void	Window::processInput()
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    else if(glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
		glClearColor(0.4f, 0.1f, 0.2f, 1.0f);
}
