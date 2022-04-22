#include "Light.h"



Light::Light(glm::vec3 & lPos, glm::vec3 & lColor)
{
	lightPos = lPos;
	lightColor = lColor;
}

void Light::MoveLight()
{
	if (KeyInput::moveLightLeft)
		lightPos -= glm::vec3(0.01f, 0.0f, 0.0f);
	if (KeyInput::moveLightRight)
		lightPos += glm::vec3(0.01f, 0.0f, 0.0f);
	if (KeyInput::moveLightForward)
		lightPos -= glm::vec3(0.0f, 0.0f, 0.01f);
	if (KeyInput::moveLightBack)
		lightPos += glm::vec3(0.0f, 0.0f, 0.01f);
	if (KeyInput::moveLightUp)
		lightPos += glm::vec3(0.0f, 0.01f, 0.0f);
	if (KeyInput::moveLightDown)
		lightPos -= glm::vec3(0.0f, 0.01f, 0.0f);
}

glm::vec3 & Light::GetLightColor()
{
	return lightColor;
}

glm::vec3 & Light::GetLightPos()
{
	return lightPos;
}

void Light::MoveLightAround()
{
	float raidus = 2.0f;

	float x = sin(glfwGetTime())*raidus;
	float z = cos(glfwGetTime())*raidus;

	glm::vec3 lightPosition = glm::vec3(x, 0.0f, z);

	lightPos = lightPosition;
}