/*************************************************************
 * File              : VBO.cpp
 * Author            : Pierre Cariou <pierrecariou@outlook.fr>
 * Date              : 16.07.2022
 * Last Modified Date: 16.07.2022
 * Last Modified By  : Pierre Cariou <pierrecariou@outlook.fr>
 *************************************************************/

#include <VBO.hpp>

VBO::VBO()
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
	// std::cout << "HELLO: " << sizeof(vertices) << std::endl;
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// how to interpret data
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}
