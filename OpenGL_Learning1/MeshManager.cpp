#include "MeshManager.h"

void MeshManager::setMeshStructureBuilder(std::shared_ptr<IMeshStructureBuilder> p_meshStructBuilder)
{
    m_meshStructBuilder = p_meshStructBuilder;
}

std::shared_ptr<Mesh> MeshManager::constructMesh(std::string p_vertexShaderPath, std::string p_fragmentShaderPath, ModelType p_modelType, MeshType p_meshType) const
{
    std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>(p_vertexShaderPath, p_fragmentShaderPath, p_modelType, p_meshType);
    mesh->setMeshStructure(m_meshStructBuilder->buildVerticiesCoords()->buildNormalCoords()->buildTextureCoords()->buildIndicies()->build());
    return mesh;
}
