#include <GLFW\glfw3.h>

#pragma once


class Time
{
public:
	Time();

	float DeltaTime();

private:
	float deltaTime;
	float currentTime;
	float lastTime;
	float FPS;
};

