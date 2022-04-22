#include <glad.h>
#include "FrameBufferObject.h"
#include <string>
#include <SOIL.h>
#include <vector>

#pragma once

enum TypeOfDrawing
{
	LINEAR = GL_LINEAR,
	NEARST = GL_NEAREST
};

enum TypeOfWraping
{
	REPEAT = GL_REPEAT,
	MIRRORED_REPEAT = GL_MIRRORED_REPEAT,
	CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE,
	CLAMP_TO_BORDER = GL_CLAMP_TO_BORDER
};

enum TextureGL
{
	TEXTURE0 = GL_TEXTURE0,
	TEXTURE1 = GL_TEXTURE1,
	TEXTURE2 = GL_TEXTURE2
};

enum TypeOfTexture
{
	CUBE_MAP = 0,
	NORMAL_TEXTURE
};

class Texture
{
public:

	Texture(int width, int heigh);

	Texture(const char * pathToTexture,TypeOfDrawing drawingType,TypeOfWraping wrapingType);

	Texture(std::vector<const char *> & faces, TypeOfDrawing drawingType, TypeOfWraping wrapingType,TypeOfTexture typeOfTexture);

	~Texture();

	void Set(GLint uniformLocation, int textureId);

	void ActiveTexture(TextureGL texture);

	void BindTextureID(TextureGL texture);

	void ActiveSkyBoxTexture(TextureGL texture);

	GLuint GetTextureId();

	GLuint GetTextureFrameBuffer();

	GLuint GetTextureDepthBuffer();

	void ReLoadTexture(std::string pathToTexture);

	void BindFrameBuffer();

	void BindRenderBuffer();

	void UnBindFrameBuffer();

	void BindTexture();

	TypeOfDrawing typeOfDrawing;

	TypeOfWraping typeOfWraping;

private:
	GLuint textureId;

	GLuint textureFrameBuffer;

	GLuint textureDepthBuffer;
	void Init(std::string);

	void InitCubeMap(std::vector<const char *> & faces);
	void CreateDepthBufferAttachment();
	void InitFrameBufferTexture(int width, int height);

	FrameBufferObject FBO{};
};

