#include "frameBuffer.h"



frameBuffer::frameBuffer(std::string vertexShaderSource, std::string fragmentShaderSource)
	:Mesh(vertexShaderSource, fragmentShaderSource, ModelType::WithoutEBO) 
{

}

void frameBuffer::CreateMesh()
{
	VerticiesCoords vert[]
	{
		{-1.0f, -1.0f, 0.0f},
		{1.0f, -1.0f, 0.0f},
		{-1.0f,  1.0f, 0.0f},
		{-1.0f,  1.0f, 0.0f},
		{1.0f, -1.0f, 0.0f},
		{1.0f,  1.0f, 0.0f}
	};

	TextCoords textCor[] =
	{
		{ 0.0f, 0.0f },
		{ 1.0f, 0.0f },
		{ 1.0f, 1.0f },
		{ 1.0f, 1.0f },
		{ 0.0f, 1.0f },
		{ 0.0f, 0.0f }
	};


	NormalCoords normCoords[] =
	{
		{ 0.0f,  0.0f, -1.0f },
		{ 0.0f,  0.0f, -1.0f },
		{ 0.0f,  0.0f, -1.0f },
		{ 0.0f,  0.0f, -1.0f },
		{ 0.0f,  0.0f, -1.0f },
		{ 0.0f,  0.0f, -1.0f },

		{ 0.0f,  0.0f, 1.0f },
		{ 0.0f,  0.0f, 1.0f },
		{ 0.0f,  0.0f, 1.0f },
		{ 0.0f,  0.0f, 1.0f },
		{ 0.0f,  0.0f, 1.0f },
		{ 0.0f,  0.0f, 1.0f },

		{ -1.0f,  0.0f, 0.0f },
		{ -1.0f,  0.0f, 0.0f },
		{ -1.0f,  0.0f, 0.0f },
		{ -1.0f,  0.0f, 0.0f },
		{ -1.0f,  0.0f, 0.0f },
		{ -1.0f,  0.0f, 0.0f },

		{ 1.0f,  0.0f, 0.0f },
		{ 1.0f,  0.0f, 0.0f },
		{ 1.0f,  0.0f, 0.0f },
		{ 1.0f,  0.0f, 0.0f },
		{ 1.0f,  0.0f, 0.0f },
		{ 1.0f,  0.0f, 0.0f },

		{ 0.0f,  -1.0f, 0.0f },
		{ 0.0f,  -1.0f, 0.0f },
		{ 0.0f,  -1.0f, 0.0f },
		{ 0.0f,  -1.0f, 0.0f },
		{ 0.0f,  -1.0f, 0.0f },
		{ 0.0f,  -1.0f, 0.0f },

		{ 0.0f,  1.0f, 0.0f },
		{ 0.0f,  1.0f, 0.0f },
		{ 0.0f,  1.0f, 0.0f },
		{ 0.0f,  1.0f, 0.0f },
		{ 0.0f,  1.0f, 0.0f },
		{ 0.0f,  1.0f, 0.0f },
	};
	GLuint indi[]
	{
		0,1,2,
		0,3,2,
		5,1,2,
		5,6,2,
		6,7,4,
		6,5,4,
		7,3,0,
		7,4,0,
		4,5,1,
		4,0,1,
		7,3,2,
		7,6,2
	};

	verticies = std::vector<VerticiesCoords>(vert, std::end(vert));
	indicies = std::vector<GLuint>(indi, std::end(indi));
	textureCoords = std::vector<TextCoords>(textCor, std::end(textCor));
	normals = std::vector<NormalCoords>(normCoords, std::end(normCoords));
}
