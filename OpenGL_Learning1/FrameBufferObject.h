#include <glad.h>
#include <iostream>
#pragma once

class FrameBufferObject
{
public:
	FrameBufferObject()=default;

	void GenFrameBuffer();

	void BindFrameBuffer();

	void GenRenderBuffer(int width, int height);

	void UnBindFrameBuffer();

	GLuint GetFrameBufferId();

private:

	GLuint rbo;

	GLuint framebufferId;

};

