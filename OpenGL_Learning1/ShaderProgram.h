#include <glad.h>
#include <glm.hpp>
#include <matrix_transform.hpp>
#include <type_ptr.hpp>
#include "Logger.h"
#include <iostream>

#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

class ShaderProgram
{
public:

	ShaderProgram(GLuint vertexShaderId, GLuint fragmentShadeId)noexcept;

	ShaderProgram(const ShaderProgram & shaderProgram)noexcept;
	
	ShaderProgram(const ShaderProgram && shaderProgram);

	ShaderProgram operator = (const ShaderProgram & shaderProgram);

	~ShaderProgram();

	GLint UniformLocation(const char * nameOfUniform);

	GLuint & GetVertexShaderID();

	GLuint & GetFragmentShaderID();

	GLuint & GetProgramId();

	void Bind();

	void UnBind();

	void ReLoad(GLuint vId, GLuint fId);

	void SetMartix4Uniform(glm::mat4 & matrixValue,std::string pathToMatrixValue);

	void SetVec3(std::string, GLfloat, GLfloat, GLfloat);

	void SetVec3(std::string, glm::vec3 &);

	void SetVec4(std::string pathToVec3Value, glm::vec4 & vec4);

	void SetFloat(std::string, float);

private:
	void Init(GLuint vertexShaderId, GLuint fragmentShadeId);

	GLuint vertexID;
	GLuint fragmentID;

	GLuint programId;
};

#endif

