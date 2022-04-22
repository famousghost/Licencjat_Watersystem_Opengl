#include <GLFW\glfw3.h>
#include "Logger.h"
#include <fstream>

#pragma once

class Window
{
public:

	Window(int width, int height, char * title);

	~Window();

	GLFWwindow * GetWindow();

	bool IsOpen();

	int GetWidth();

	int GetHeight();

private:
	GLFWwindow * window;

	std::fstream logFile;

	void Init(int width, int height, char * title);

	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

	int width;

	int height;

	std::string error;
};

