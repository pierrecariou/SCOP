/*************************************************************
 * File              : Shader.cpp
 * Author            : Pierre Cariou <pierrecariou@outlook.fr>
 * Date              : 17.07.2022
 * Last Modified Date: 17.07.2022
 * Last Modified By  : Pierre Cariou <pierrecariou@outlook.fr>
 *************************************************************/

#include <Shader.hpp>

Shader::Shader(const char *shaderSource, GLenum shaderType) : shaderSource(shaderSource)
{
	shaderId = glCreateShader(shaderType);
	compile();
}

Shader::~Shader()
{
	glDeleteShader(shaderId);
}

unsigned int	Shader::getId()
{
	return shaderId;
}

void	Shader::compile()
{
	glShaderSource(shaderId, 1, &shaderSource, NULL);
	glCompileShader(shaderId);

	// check if success
	int  success;
	char infoLog[512];
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
	if(!success)
	{
    	glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
    	std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
}
