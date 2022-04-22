#include "Texture.h"



void Texture::Init(std::string pathToTexture)
{
	int width, height;
	unsigned char* image1;
	// Load and create a texture 
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId); // All upcoming GL_TEXTURE_2D operations now have effect on this texture object
											// Set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, typeOfWraping);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, typeOfWraping);
	// Set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, typeOfDrawing);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, typeOfDrawing);
	// Load image, create texture and generate mipmaps
	image1 = SOIL_load_image(pathToTexture.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image1);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image1);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
}

void Texture::InitCubeMap(std::vector<const char *> & faces)
{
	unsigned char* image;
	int width, height;

	// Load and create a texture 
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureId); // All upcoming GL_TEXTURE_2D operations now have effect on this texture object
											 // Set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, typeOfWraping);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, typeOfWraping);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, typeOfWraping);
	// Set texture filtering parameters
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, typeOfDrawing);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, typeOfDrawing);
	// Load image, create texture and generate mipmaps

	for (int i = 0; i < faces.size(); ++i)
	{
		image = SOIL_load_image(faces[i], &width, &height, 0, SOIL_LOAD_RGB);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(GL_TEXTURE_CUBE_MAP);
		SOIL_free_image_data(image);
		 // Unbind texture when done, so we won't accidentily mess up our texture.
	}
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}

void Texture::CreateDepthBufferAttachment()
{
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT32, 800, 600, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, typeOfDrawing);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, typeOfDrawing);

	glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, textureId, 0);
	glBindTexture(GL_TEXTURE_2D, 0);

}

void Texture::InitFrameBufferTexture(int width,int height)
{

	FBO.GenFrameBuffer();
	// Load and create a texture 
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId); // All upcoming GL_TEXTURE_2D operations now have effect on this texture object

	// Set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, typeOfDrawing);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, typeOfDrawing);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,GL_TEXTURE_2D, textureId, 0);
	
	FBO.GenRenderBuffer(width, height);

	//CreateDepthBufferAttachment();

	glBindTexture(GL_TEXTURE_2D, 0);


}

Texture::Texture(const char * pathToTexture, TypeOfDrawing drawingType, TypeOfWraping wrapingType)
	:typeOfDrawing(drawingType),typeOfWraping(wrapingType)
{
	Init(pathToTexture);
}

Texture::Texture(int width, int height)
	:typeOfDrawing(LINEAR), typeOfWraping(CLAMP_TO_EDGE)
{
	InitFrameBufferTexture(width,height);
}

Texture::Texture(std::vector<const char *> &  faces, TypeOfDrawing drawingType, TypeOfWraping wrapingType, TypeOfTexture typeOfTexture)
	:typeOfDrawing(drawingType), typeOfWraping(wrapingType)
{
	InitCubeMap(faces);
}


Texture::~Texture()
{
	glDeleteTextures(1,&textureId);
}

void Texture::Set(GLint uniformLocation,int textureId)
{
	glUniform1i(uniformLocation, textureId);
}

void Texture::ActiveTexture(TextureGL texture)
{
	glActiveTexture(texture);

	glBindTexture(GL_TEXTURE_2D, textureId);
}

void Texture::BindTextureID(TextureGL texture)
{
	glActiveTexture(texture);

	glBindTexture(GL_TEXTURE_2D, textureId);
}

void Texture::ActiveSkyBoxTexture(TextureGL texture)
{
	glActiveTexture(texture);

	glBindTexture(GL_TEXTURE_CUBE_MAP, textureId);
}

void Texture::ReLoadTexture(std::string pathToTexture)
{
	glDeleteTextures(1, &textureId);
	Init(pathToTexture);
}

void Texture::BindFrameBuffer()
{
	FBO.BindFrameBuffer();
}

void Texture::BindRenderBuffer()
{

}

void Texture::UnBindFrameBuffer()
{
	FBO.UnBindFrameBuffer();
}


void Texture::BindTexture()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

GLuint Texture::GetTextureId()
{
	return textureId;
}

GLuint Texture::GetTextureFrameBuffer()
{
	return textureFrameBuffer;
}

GLuint Texture::GetTextureDepthBuffer()
{
	return textureDepthBuffer;
}
