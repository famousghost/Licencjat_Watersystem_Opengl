#pragma once
#include "IMeshStructureBuilder.h"
#include "Mesh.h"

class MeshManager
{
public:
    void setMeshStructureBuilder(std::shared_ptr<IMeshStructureBuilder> p_meshStructBuilder);

    std::shared_ptr<Mesh> constructMesh(std::string p_vertexShaderPath, std::string p_fragmentShaderPath, ModelType p_modelType, MeshType p_meshType) const;

private:
    std::shared_ptr<IMeshStructureBuilder> m_meshStructBuilder;
};

