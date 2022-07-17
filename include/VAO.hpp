/*************************************************************
 * File              : VAO.hpp
 * Author            : Pierre Cariou <pierrecariou@outlook.fr>
 * Date              : 17.07.2022
 * Last Modified Date: 17.07.2022
 * Last Modified By  : Pierre Cariou <pierrecariou@outlook.fr>
 *************************************************************/

#ifndef VAO_HPP
# define VAO_HPP

class VAO {
	public:
		VAO();
		~VAO();

		unsigned int getVAOId();

	private:
		unsigned int	VAOId;
};

#endif
