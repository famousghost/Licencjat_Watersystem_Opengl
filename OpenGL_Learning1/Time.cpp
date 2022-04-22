#include "Time.h"
#include <iostream>



Time::Time()
{
	currentTime = 0.0f;
	deltaTime = 0.0f;
	lastTime = 0.0f;
	FPS = 0.0f;
}

float Time::DeltaTime()
{
	currentTime = glfwGetTime();
	deltaTime = currentTime - lastTime;
	lastTime = currentTime;
	FPS = 1/deltaTime;
	//std::cout << FPS << std::endl;
	return deltaTime;
}
