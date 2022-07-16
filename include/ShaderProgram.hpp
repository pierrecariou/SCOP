/*************************************************************
 * File              : ShaderProgram.hpp
 * Author            : Pierre Cariou <pierrecariou@outlook.fr>
 * Date              : 16.07.2022
 * Last Modified Date: 16.07.2022
 * Last Modified By  : Pierre Cariou <pierrecariou@outlook.fr>
 *************************************************************/

#ifndef SHADERPROGRAM_HPP
# define SHADERPROGRAM_HPP

class ShaderProgram {
	public:
		ShaderProgram(Shader *vertexShader, Shader *fragmentShader);
		~ShaderProgram();

	private:
		void	linkShaders();

		// attributes
		unsigned int programId;
		Shader	*vertexShader;
		Shader	*fragmentShader;
};

#endif
