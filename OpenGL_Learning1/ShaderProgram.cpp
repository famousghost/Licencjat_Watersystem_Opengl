#include "ShaderProgram.h"
#include <iostream>


void ShaderProgram::Init(GLuint vertexShaderId, GLuint fragmentShadeId)
{
	GLint success;
	GLchar errorBuffer[512];

	vertexID = vertexShaderId;
	fragmentID = fragmentShadeId;

	programId = glCreateProgram();
	glAttachShader(programId, vertexID);
	glAttachShader(programId, fragmentID);
	glLinkProgram(programId);

	glGetProgramiv(programId, GL_LINK_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(programId, 512,NULL, errorBuffer);
        LOG("Class ShaderProgram - Cannot Link Shader Program", LogType::ERR);
	}
}


ShaderProgram::ShaderProgram(GLuint vertexShaderId, GLuint fragmentShadeId)noexcept
{
	vertexID = vertexShaderId;
	fragmentID = fragmentShadeId;
	Init(vertexID, fragmentID);
}

ShaderProgram::ShaderProgram(const ShaderProgram & shaderProgram)noexcept
{
	Init(shaderProgram.vertexID, shaderProgram.fragmentID);
}

ShaderProgram::ShaderProgram(const ShaderProgram && shaderProgram)
{
	Init(shaderProgram.vertexID,shaderProgram.fragmentID);
}

ShaderProgram ShaderProgram::operator=(const ShaderProgram & shaderProgram)
{
	Init(shaderProgram.vertexID, shaderProgram.fragmentID);
	return *this;
}


ShaderProgram::~ShaderProgram()
{
	glUseProgram(NULL);
	glDetachShader(programId, vertexID);
    glDetachShader(programId, fragmentID);
	glDeleteProgram(programId);
}

GLint ShaderProgram::UniformLocation(const char * nameOfUniform)
{
	return glGetUniformLocation(programId,nameOfUniform);
}

GLuint & ShaderProgram::GetVertexShaderID()
{
	return vertexID;
}

GLuint & ShaderProgram::GetFragmentShaderID()
{
	return fragmentID;
}


GLuint & ShaderProgram::GetProgramId()
{
	return programId;
}

void ShaderProgram::Bind()
{
	glUseProgram(programId);
}

void ShaderProgram::UnBind()
{
	glUseProgram(NULL);
}

void ShaderProgram::ReLoad(GLuint vId,GLuint fId)
{
	glDetachShader(programId, vertexID);
	glDetachShader(programId, fragmentID);
	glDeleteProgram(programId);
	Init(vId, fId);
}

void ShaderProgram::SetMartix4Uniform(glm::mat4 & matrixValue, std::string pathToMatrixValue)
{
	Bind();
	GLint matrixLoc = glGetUniformLocation(programId, pathToMatrixValue.c_str());
	glUniformMatrix4fv(matrixLoc, 1, GL_FALSE, glm::value_ptr(matrixValue));
}

void ShaderProgram::SetVec3(std::string pathToVec3Value, GLfloat x, GLfloat y, GLfloat z)
{
	Bind();
	GLint vec3Loc = glGetUniformLocation(programId, pathToVec3Value.c_str());
	glUniform3f(vec3Loc, x, y, z);
}

void ShaderProgram::SetVec3(std::string pathToVec3Value, glm::vec3 & vec3)
{
	Bind();
	GLint vec3Loc = glGetUniformLocation(programId, pathToVec3Value.c_str());
	glUniform3fv(vec3Loc, 1, glm::value_ptr(vec3));
}

void ShaderProgram::SetVec4(std::string pathToVec3Value, glm::vec4 & vec4)
{
	Bind();
	GLint vec3Loc = glGetUniformLocation(programId, pathToVec3Value.c_str());
	glUniform4fv(vec3Loc, 1, glm::value_ptr(vec4));
}

void ShaderProgram::SetFloat(std::string pathTofloatValue, float floatVariable)
{
	Bind();
	GLint floatValueLoc = glGetUniformLocation(programId, pathTofloatValue.c_str());
	glUniform1f(floatValueLoc, floatVariable);
}