#include "MeshBuilder.h"


#pragma once

class Light
{
public:

	Light(glm::vec3 & lPos, glm::vec3 & lColor);

	void MoveLight();

	glm::vec3 & GetLightColor();

	glm::vec3 & GetLightPos();

	void MoveLightAround();

private:
	glm::vec3 lightPos;

	glm::vec3 lightColor;
};

