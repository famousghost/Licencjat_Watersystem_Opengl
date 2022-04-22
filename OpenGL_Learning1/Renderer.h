#include <glad.h>
#include <GLFW\glfw3.h>
#include "Camera.h"
#include "CubeBuilder.h"
#include "WaterBuilder.h"
#include "PictureBuilder.h"
#include "SphereBuilder.h"
#include "TerrainBuilder.h"
#include "PyramidBuilder.h"
#include "KeyInput.h"
#include "MeshBuilder.h"
#include <memory>
#include <iostream>


enum DRAW_TYPE
{
	FILL = GL_FILL,
	LINE = GL_LINE
};

#pragma once

class Renderer
{
public:
	Renderer();

	void Clear();

	void ReloadShader(std::string ,std::string, MeshBuilder & meshBuilder);

	void Draw(MeshBuilder & meshBuilder);

	void DrawSkyBox(MeshBuilder & meshBuilder, Camera & camera);

	void Draw(MeshBuilder & meshBuilder, DRAW_TYPE drawingType);

	void DrawFrameBuffer(MeshBuilder & meshBuilder, int s_width, int s_height);

	void SetMesh(MeshBuilder & meshBuilder,Camera & camera);

	std::string ReLoadPathToTexture(std::string pathToTexture);

private:

	float lastFrameTime;
	float deltaTime;

};