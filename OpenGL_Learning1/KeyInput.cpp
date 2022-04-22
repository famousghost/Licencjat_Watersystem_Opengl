#include "KeyInput.h"
#include <iostream>
float KeyInput::lastX = 400.0f;
float KeyInput::lastY = 300.0f;
float KeyInput::xOffset = 0.0f;
float KeyInput::yOffset = 0.0;

//Adding and reloading shader input
bool KeyInput::reLoadShader = false;
bool KeyInput::AddCube = false;

//move our camera in 3d space
bool KeyInput::moveFront = false;
bool KeyInput::moveRight = false;
bool KeyInput::moveBack = false;
bool KeyInput::moveLeft = false;
bool KeyInput::inversPitch = false;

//set firstTime Camera lastX pos and lastY pos 
bool KeyInput::firstCamera = true;

//Moving Light Ovject
bool KeyInput::moveLightLeft = false;
bool KeyInput::moveLightRight = false;
bool KeyInput::moveLightForward = false;
bool KeyInput::moveLightBack = false;
bool KeyInput::moveLightUp = false;
bool KeyInput::moveLightDown = false;

GLfloat KeyInput::changeStateOfMixTextures = 0.0f;
GLfloat KeyInput::Xaxis = 0.0f;
GLfloat KeyInput::Yaxis = 0.0f;

double KeyInput::fov = 45.0f;

void KeyInput::KeyInputCallerBack(GLFWwindow * window, int key, int scancode, int state, int mods)
{
	//Exit from appliaction
	if (state == GLFW_PRESS)
	{
		if (key == GLFW_KEY_I)
		{
			inversPitch = true;
		}
		//Reaload shader and Cube add in progress...
		if (key == GLFW_KEY_R)
		{
			reLoadShader = true;
		}

		if (key == GLFW_KEY_C)
		{
			AddCube = true;
		}

		//Close Window
		if (key == GLFW_KEY_ESCAPE)
		{
			glfwSetWindowShouldClose(window, true);
		}

		//Light Object Move
		if (key == GLFW_KEY_A)
		{
			moveLightLeft = true;
		}
		if (key == GLFW_KEY_D)
		{
			moveLightRight = true;
		}
		if (key == GLFW_KEY_W)
		{
			moveLightForward = true;
		}
		if (key == GLFW_KEY_S)
		{
			moveLightBack = true;
		}
		if (key == GLFW_KEY_U)
		{
			moveLightUp = true;
		}
		if (key == GLFW_KEY_J)
		{
			moveLightDown = true;
		}

		//Camera Move
		if (key == GLFW_KEY_UP)
		{
			moveFront = true;
		}
		if (key == GLFW_KEY_DOWN)
		{
			moveBack = true;
		}
		if (key == GLFW_KEY_LEFT)
		{
			moveLeft = true;
		}
		if (key == GLFW_KEY_RIGHT)
		{
			moveRight = true;
		}
	}
	else if (state == GLFW_RELEASE)
	{
		if (key == GLFW_KEY_I)
		{
			inversPitch = false;
		}
		//Light Object Move
		if (key == GLFW_KEY_A)
		{
			moveLightLeft = false;
		}

		if (key == GLFW_KEY_D)
		{
			moveLightRight = false;
		}
		if (key == GLFW_KEY_W)
		{
			moveLightForward = false;
		}
		if (key == GLFW_KEY_S)
		{
			moveLightBack = false;
		}
		if (key == GLFW_KEY_U)
		{
			moveLightUp = false;
		}
		if (key == GLFW_KEY_J)
		{
			moveLightDown = false;
		}

		//Camera Move
		if (key == GLFW_KEY_UP)
		{
			moveFront = false;
		}
		if (key == GLFW_KEY_C)
		{
			AddCube = false;
		}
		if (key == GLFW_KEY_DOWN)
		{
			moveBack = false;
		}
		if (key == GLFW_KEY_LEFT)
		{
			moveLeft = false;
		}
		if (key == GLFW_KEY_RIGHT)
		{
			moveRight = false;
		}
	}
}

void KeyInput::MouseCallBack(GLFWwindow * window, double xPos, double yPos)
{

	if (firstCamera)
	{
		lastX = xPos;
		lastY = yPos;
		firstCamera = false;
	}

	xOffset = xPos - lastX;
	yOffset = lastY - yPos;

	lastX = xPos;
	lastY = yPos;

}

void KeyInput::scroll_callback(GLFWwindow * window, double xoffset, double yoffset)
{
	if (fov >= 1.0f && fov <= 45.0f)
		fov -= yoffset;
	if (fov <= 1.0f)
		fov = 1.0f;
	if (fov >= 45.0f)
		fov = 45.0f;
}

KeyInput::KeyInput(GLFWwindow * window)
{
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetKeyCallback(window, KeyInputCallerBack);
	glfwSetCursorPosCallback(window, MouseCallBack);
	glfwSetScrollCallback(window, scroll_callback);
}
