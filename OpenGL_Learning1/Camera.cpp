#include "Camera.h"
#include <iostream>



Camera::Camera(Window & window,glm::vec3 & cam, float fieldOfView)
{
	screenHeight = window.GetHeight();
	screenWidth = window.GetWidth();

	cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	cameraFront = glm::vec3(0.0f, 0.0f, 1.0f);
	cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	yaw = -90.0f;
	pitch = 0.0f;
	pitchChanger = -35.0f;

	cameraPos = -cam;
	this->projection =  glm::perspective(glm::radians(fieldOfView), 
		                                 (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
}

void Camera::SetCamera(glm::vec3 & cam, float fieldOfView)
{
	cameraPos = -cam;
	this->projection = glm::perspective(glm::radians(fieldOfView), (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
}

void Camera::SetViewMatrix()
{
	this->view = glm::mat4(glm::mat3(view));
}

void Camera::LookAtCamera()
{

	//How to make directions//
	//Cross Product Of Directions//

	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);

	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));

	glm::vec3 cameraUp = glm::normalize(glm::cross(cameraDirection, cameraRight));

	float radius = 10.0f;
	float camX = sin(glfwGetTime()) * radius;
	float camZ = cos(glfwGetTime()) * radius;
	view = glm::lookAt(glm::vec3(camX, 0.0f, camZ), cameraDirection, cameraUp);
}

glm::vec3 & Camera::GetFrontOfCamera()
{
	return cameraPos + glm::vec3(0.0f, 0.0f, -3.0f);
}

void Camera::ZoomCamera()
{
	float fieldOfView = KeyInput::fov;
	this->projection = glm::perspective(glm::radians(fieldOfView), (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
}

void Camera::RotateCamera(float xSensitivity, float ySensitivity)
{
	KeyInput::xOffset *= xSensitivity;
	KeyInput::yOffset *= ySensitivity;
	yaw += KeyInput::xOffset;
	pitch += KeyInput::yOffset;

	if (pitch > 89.0f)
	{
		pitch = 89.0f;
	}
	else if (pitch < -89.0f)
	{
		pitch = -89.0f;
	}

	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(front);
}

void Camera::InverPitch()
{
    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(-pitch));
    front.y = sin(glm::radians(-pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(-pitch));
    cameraFront = glm::normalize(front);
}

void Camera::BackToNormal()
{
    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(front);
}

void Camera::MoveCamera(float speed)
{
	if (KeyInput::moveFront)
	{
		cameraPos += (speed * cameraFront);
	}
	if (KeyInput::moveBack)
	{
		cameraPos -= (speed * cameraFront);
	}
	if (KeyInput::moveLeft)
	{
		cameraPos -= ((glm::normalize(glm::cross(cameraFront, cameraUp))) * speed);
	}
	if (KeyInput::moveRight)
	{
		cameraPos += ((glm::normalize(glm::cross(cameraFront, cameraUp))) * speed);
	}

	this->view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}

void Camera::ResetMatrixView()
{
	this->view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}

glm::mat4 & Camera::GetViewMatrix()
{
	return view;
}

glm::mat4 & Camera::GetProjectionMatrix()
{
	return projection;
}

glm::vec3 & Camera::GetCameraPos()
{
	return cameraPos;
}

void Camera::setPitch(float p_pitch)
{
	this->pitch = p_pitch;
}