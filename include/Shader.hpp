/*************************************************************
 * File              : Shader.hpp
 * Author            : Pierre Cariou <pierrecariou@outlook.fr>
 * Date              : 16.07.2022
 * Last Modified Date: 16.07.2022
 * Last Modified By  : Pierre Cariou <pierrecariou@outlook.fr>
 *************************************************************/

#ifndef SHADER_HPP
# define SHADER_HPP

class Shader {
	public:
		Shader(const char *shaderSource, GLenum shaderType);
		~Shader();

		unsigned int	getId();

	private:
		void	compile();

		// attributes
		unsigned int	shaderId;
		const char	*shaderSource;
};

#endif
