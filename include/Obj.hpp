#ifndef OBJ_HPP 
# define OBJ_HPP

#include <glm/glm.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <string.h>

class Obj
{
	public:
		Obj(char *filePath);
		~Obj();

		void	initialize();

	private:
		char	*filePath;
		std::vector < glm::vec3 > out_vertices;
		std::vector < glm::vec2 > out_uvs;
		std::vector < glm::vec3 > out_normals;
};

#endif
