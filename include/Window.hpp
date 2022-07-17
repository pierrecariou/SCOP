/*************************************************************
 * File              : Window.hpp
 * Author            : Pierre Cariou <pierrecariou@outlook.fr>
 * Date              : 15.07.2022
 * Last Modified Date: 15.07.2022
 * Last Modified By  : Pierre Cariou <pierrecariou@outlook.fr>
 *************************************************************/

#ifndef WINDOW_HPP
# define WINDOW_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
//#include <glm/glm.hpp>
#include <iostream>

class Window
{
	public:
		Window();
		~Window();

		void	draw(unsigned int shaderProgramId, unsigned int VAOId);

	private:
		void	initialize();
		void	create();
		void	processInput();

//		static void	framebuffer_size_callback(GLFWwindow* window, int width, int height);

		// attributes
		GLFWwindow* window;
};

void	framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

#endif
