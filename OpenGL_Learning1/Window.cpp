#include "Window.h"
#include "KeyInput.h"
#include <iostream>
#include <memory>
#include <string>


void Window::Init(int width, int height, char * title)
{
	this->width = width;
	this->height = height;
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	glfwMakeContextCurrent(window);
	std::shared_ptr<KeyInput> keyInput(new KeyInput(window));
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	if (window == nullptr)
	{
		LOG("Class Window - Cannot Initialize Window", LogType::ERR);
		return;
	}
}

void Window::framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
	glViewport(0, 0, width, height);
}

Window::Window(int width, int height, char * title)
{
	Init(width, height, title);
}


Window::~Window()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

GLFWwindow * Window::GetWindow()
{
	return window;
}

bool Window::IsOpen()
{
	return !glfwWindowShouldClose(window);
}

int Window::GetWidth()
{
	return width;
}

int Window::GetHeight()
{
	return height;
}
