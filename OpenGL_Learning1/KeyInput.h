#include <GLFW\glfw3.h>


#pragma once
class KeyInput
{
public:

	KeyInput(GLFWwindow * window);

	static void KeyInputCallerBack(GLFWwindow * window, int key, int scancode, int state, int mods);
	static void MouseCallBack(GLFWwindow * window, double xPos, double yPos);
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

	static bool moveFront;
	static bool moveRight;
	static bool moveBack;
	static bool moveLeft;
	static bool reLoadShader;
	static bool firstCamera;
	static bool AddCube;

	static bool moveLightLeft;
	static bool moveLightRight;
	static bool moveLightForward;
	static bool moveLightBack;
	static bool moveLightUp;
	static bool moveLightDown;
	static bool inversPitch;

	static GLfloat changeStateOfMixTextures;
	static GLfloat Xaxis;
	static GLfloat Yaxis;

	static float xOffset;
	static float yOffset;

	static double fov;

	static float lastX;
	static float lastY;
};