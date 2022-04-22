#include "Shader.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

void Shader::Init(char * pathToShader)
{

	std::fstream file;
	std::stringstream shaderProgramSource;
	std::string shaderSourceString;

	//Open Shader File
	file.open(pathToShader,std::ios::in);
	shaderProgramSource << file.rdbuf();
	file.close();
	shaderSourceString = shaderProgramSource.str();
	const char * shaderProgram = shaderSourceString.c_str();

	LOG(shaderProgram, LogType::DBG);

	GLint success;
	GLchar errBuffers[512];

	shaderId = glCreateShader(shaderType);

	glShaderSource(shaderId, 1, &shaderProgram, NULL);

	glCompileShader(shaderId);

	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(shaderId, 512, NULL, errBuffers);

		LOG("Class ShaderProgram - Cannot Open File (VertexShader or FragmentShader)", LogType::ERR);
	}
}

Shader::Shader(char * pathToShader, ShaderType shaderType)
	:shaderType(shaderType)
{
	Init(pathToShader);
}


Shader::~Shader()
{
	glDeleteShader(shaderId);
}

GLuint Shader::GetShaderId()
{
	return shaderId;
}

void Shader::ReLoadShader(char * shaderPath)
{
	Init(shaderPath);
}