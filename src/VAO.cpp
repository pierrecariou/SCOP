/*************************************************************
 * File              : VAO.cpp
 * Author            : Pierre Cariou <pierrecariou@outlook.fr>
 * Date              : 16.07.2022
 * Last Modified Date: 16.07.2022
 * Last Modified By  : Pierre Cariou <pierrecariou@outlook.fr>
 *************************************************************/

#include <VAO.hpp>

VAO::VAO()
{
	glGenVertexArrays(1, &VAOId); 
	glBindVertexArray(VAOId);
}

VAO::~VAO()
{

}

unsigned int	VAO::getVAOId()
{
	return VAOId;
}
