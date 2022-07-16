/*************************************************************
 * File              : VBO.hpp
 * Author            : Pierre Cariou <pierrecariou@outlook.fr>
 * Date              : 16.07.2022
 * Last Modified Date: 16.07.2022
 * Last Modified By  : Pierre Cariou <pierrecariou@outlook.fr>
 *************************************************************/

#ifndef VBO_HPP
# define VBO_HPP

class VBO {
	public:
		VBO(float *vertices);
		~VBO();

	private:
		void	store();

		unsigned int	VBOId;
		float			*vertices;
};

#endif
