#include <glad.h>
#include "Logger.h"
#include "KeyInput.h"

#pragma once

enum ShaderType
{
	VERTEX_SHADER = GL_VERTEX_SHADER,
	FRAGMENT_SHADER = GL_FRAGMENT_SHADER
};

#pragma once
class Shader
{

public:

	Shader(char * pathToShader, ShaderType shaderType);

	~Shader();

	GLuint GetShaderId();

	void ReLoadShader(char * shaderPath);

private:
	ShaderType shaderType;

	GLuint shaderId;

	void Init(char * pathToShader);


};

