/*************************************************************
 * File              : ShaderProgram.cpp
 * Author            : Pierre Cariou <pierrecariou@outlook.fr>
 * Date              : 16.07.2022
 * Last Modified Date: 16.07.2022
 * Last Modified By  : Pierre Cariou <pierrecariou@outlook.fr>
 *************************************************************/

#include <ShaderProgram.hpp>

ShaderProgram::ShaderProgram(Shader *vertexShader, Shader *fragmentShader) :
	vertexShader(vertexShader), fragmentShader(fragmentShader)
{
	programId = glCreateProgram();	
	linkShaders();
}

ShaderProgram::~ShaderProgram()
{

}

void	ShaderProgram::linkShaders()
{
	glAttachShader(programId, vertexShader->getId());
	glAttachShader(programId, fragmentShader->getId());
	glLinkProgram(programId);

	// check if succes
	int  success;
	char infoLog[512];

	glGetProgramiv(programId, GL_LINK_STATUS, &success);
	if (!success) {
    	glGetProgramInfoLog(programId, 512, NULL, infoLog);
    	std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	// activate program
	glUseProgram(programId);
	// delete shaders
	delete vertexShader;
	delete fragmentShader;
}
