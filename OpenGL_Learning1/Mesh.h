#include "Logger.h"
#include "defines.h"
#include <vector>
#include <matrix_transform.hpp>
#include "MeshStructure.h"
#include <type_ptr.hpp>
#include <string>
#include <memory>

#pragma once

enum ShaderPathType
{
	vertexPathShader,
	fragmentPathShader
};

enum class ModelType: unsigned int
{
	WithEBO = 1,
	WithoutEBO
};

enum class MeshType : unsigned int
{
	Model = 1,
	Picture
};


class Mesh
{
public:

    Mesh() = default;
	Mesh(std::string,std::string,ModelType,MeshType);

	std::vector<VerticiesCoords> & GetVerticies();

	std::vector<NormalCoords> & GetNormals();
	
	std::vector<TextCoords> & GetTextureCoords();

	std::vector<GLuint> & GetIndicies();

	ModelType & GetModelType();

    MeshStructure & GetMeshStructure();

	std::string GetVertexShaderPath();

	std::string GetFragmentShaderPath();

	int GetIndiciesSize();

	MeshType GetMeshType();

    void setMeshStructure(MeshStructure p_meshStructure);

    void setVertexShaderPath(std::string p_vertexShaderPath);

    void setFragmentShaderPath(std::string p_fragmentShaderPath);

    void setModelType(ModelType p_modelType);

    void setMeshType(MeshType p_meshType);

private:

    MeshStructure meshStructre;

	std::string vertexShaderPath;

	std::string fragmentShaderPath;

	ModelType modelType;

	MeshType meshType;
};
