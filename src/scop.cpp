/*************************************************************
 * File              : scop.cpp
 * Author            : Pierre Cariou <pierrecariou@outlook.fr>
 * Date              : 15.07.2022
 * Last Modified Date: 15.07.2022
 * Last Modified By  : Pierre Cariou <pierrecariou@outlook.fr>
 *************************************************************/

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>

//#include "Mesh.cpp"
#include "Window.cpp"
#include "VBO.cpp"
#include "Shader.cpp"
#include "ShaderProgram.cpp"

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

const char *vertexShaderSource[6] = { "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0"};

const char *fragmentShaderSource[6] = {"#version 330 core\n"
	"out vec4 FragColor;\n"
	"void main()\n"
	"{\n"
	"FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
	"}\n"};

int		main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "please provide an object file to load as first argument" << std::endl;
		return (1);
	}
	(void)argv;
	//	Obj	object(argv[1]);

	Window *win = new Window();

	VBO vbo(vertices);
	Shader	*vertexShader = new Shader(vertexShaderSource, GL_VERTEX_SHADER);
	Shader	*fragmentShader = new Shader(fragmentShaderSource, GL_FRAGMENT_SHADER);
	ShaderProgram(vertexShader, fragmentShader);

	win->draw();
	delete win;
	return 0;
}
