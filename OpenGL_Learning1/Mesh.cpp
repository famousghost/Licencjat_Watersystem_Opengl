#include "Mesh.h"

Mesh::Mesh(std::string vertexShaderPath, std::string fragmentShaderPath, ModelType modelType,MeshType meshType)
{
	this->vertexShaderPath = vertexShaderPath;
	this->fragmentShaderPath = fragmentShaderPath;
	this->modelType = modelType;
	this->meshType = meshType;
}

std::vector<VerticiesCoords> & Mesh::GetVerticies()
{
	return meshStructre.getVerticiesCoords();
}

std::vector<NormalCoords> & Mesh::GetNormals()
{
	return meshStructre.getNormalsCoords();
}

MeshType Mesh::GetMeshType()
{
	return meshType;
}

void Mesh::setMeshStructure(MeshStructure p_meshStructure)
{
    meshStructre = p_meshStructure;
}

void Mesh::setVertexShaderPath(std::string p_vertexShaderPath)
{
    vertexShaderPath = p_vertexShaderPath;
}

void Mesh::setFragmentShaderPath(std::string p_fragmentShaderPath)
{
    fragmentShaderPath = p_fragmentShaderPath;
}

void Mesh::setModelType(ModelType p_modelType)
{
    modelType = p_modelType;
}

void Mesh::setMeshType(MeshType p_meshType)
{
    meshType = p_meshType;
}

std::vector<TextCoords> & Mesh::GetTextureCoords()
{
	return meshStructre.getTextureCoords();
}

std::vector<GLuint> & Mesh::GetIndicies()
{
	return meshStructre.getIndicies();
}

ModelType & Mesh::GetModelType()
{
	return modelType;
}

MeshStructure& Mesh::GetMeshStructure()
{
    return meshStructre;
}

std::string Mesh::GetVertexShaderPath()
{
	return vertexShaderPath;
}

std::string Mesh::GetFragmentShaderPath()
{
	return fragmentShaderPath;
}

int Mesh::GetIndiciesSize()
{
	return meshStructre.getIndicies().size();
}