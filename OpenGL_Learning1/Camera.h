#include <glad.h>
#include "KeyInput.h"
#include "Window.h"
#include <glm.hpp>
#include <matrix_transform.hpp>
#include <type_ptr.hpp>

#pragma once


class Camera
{
public:
	Camera(Window & window, glm::vec3 & cam, float fieldOfView);

	void SetCamera(glm::vec3 & cam, float fieldOfView);

	void SetViewMatrix();

	void LookAtCamera();

	glm::vec3 & GetFrontOfCamera();

	void ZoomCamera();

	void RotateCamera(float xSensitivity, float ySensitivity);

	void InverPitch();

	void BackToNormal();

	void MoveCamera(float speed);

	void ResetMatrixView();

	glm::mat4 & GetViewMatrix();

	glm::mat4 & GetProjectionMatrix();

	glm::vec3 & GetCameraPos();

	void setPitch(float p_pitch);

private:

	glm::vec3 cameraPos;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;
	glm::vec3 cameraRight;

	glm::mat4 view;
	glm::mat4 projection;

	int screenWidth;
	int screenHeight;

	float pitch;
	float yaw;
	float pitchChanger;
	float pitchBuffor;
};
