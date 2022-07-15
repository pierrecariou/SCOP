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

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	(void)argv;
	//	Obj	object(argv[1]);

	Window *win = new Window();

	win->draw();
	delete win;
	return 0;
}
