#include <Obj.hpp>

Obj::Obj(char *filePath) : filePath(filePath)
{
	std::cout << "Ok" << std::endl;	
	initialize();
}

Obj::~Obj()
{

}

void	Obj::initialize()
{
	FILE * file = fopen(filePath, "r");

	if( file == NULL ) {
		std::cout << "Impossible to open the file !" << std::endl;
		return;
	}

	std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
	std::vector< glm::vec3 > temp_vertices;
	std::vector< glm::vec2 > temp_uvs;
	std::vector< glm::vec3 > temp_normals;

	while (true) 
	{
		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		std::cout << std::string(lineHeader) << std::endl;
		if (res == EOF)
			break;
		if (!strcmp(lineHeader, "v"))
		{
			glm::vec3 vertex;
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
			temp_vertices.push_back(vertex);
		}
		else if ( strcmp( lineHeader, "f" ) == 0 )
		{
			std::string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
			if (matches != 9)
			{
				printf("File can't be read by our simple parser : ( Try exporting with other options\n");
				return;
			}
			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);
			uvIndices.push_back(uvIndex[0]);
			uvIndices.push_back(uvIndex[1]);
			uvIndices.push_back(uvIndex[2]);
			normalIndices.push_back(normalIndex[0]);
			normalIndices.push_back(normalIndex[1]);
			normalIndices.push_back(normalIndex[2]);
		}
	}
}
