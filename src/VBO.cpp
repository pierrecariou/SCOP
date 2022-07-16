/*************************************************************
 * File              : VBO.cpp
 * Author            : Pierre Cariou <pierrecariou@outlook.fr>
 * Date              : 16.07.2022
 * Last Modified Date: 16.07.2022
 * Last Modified By  : Pierre Cariou <pierrecariou@outlook.fr>
 *************************************************************/

#include <VBO.hpp>

VBO::VBO(float *vertices) : vertices(vertices)
{
	glGenBuffers(1, &VBOId); 
	glBindBuffer(GL_ARRAY_BUFFER, VBOId);
	store();
}

VBO::~VBO()
{

}

void	VBO::store()
{
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}
