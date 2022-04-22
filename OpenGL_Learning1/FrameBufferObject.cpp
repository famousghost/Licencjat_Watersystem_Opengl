#include "FrameBufferObject.h"
#include "Logger.h"

void FrameBufferObject::GenFrameBuffer()
{
	glGenFramebuffers(1, &framebufferId);
	glBindFramebuffer(GL_FRAMEBUFFER, framebufferId);
}

void FrameBufferObject::BindFrameBuffer()
{
	glBindFramebuffer(GL_FRAMEBUFFER, framebufferId);
}

void FrameBufferObject::GenRenderBuffer(int width,int height)
{
	glGenRenderbuffers(1, &rbo);
	glBindRenderbuffer(GL_RENDERBUFFER, rbo);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo); 
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
	{
        LOG("ERROR::FRAMEBUFFER:: Framebuffer is not complete!", LogType::ERR);
	}
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void FrameBufferObject::UnBindFrameBuffer()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

GLuint FrameBufferObject::GetFrameBufferId()
{
	return framebufferId;
}
