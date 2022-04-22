#pragma once
#include "defines.h"
#include <vector>
#include "KeyInput.h"
#include "MeshStructure.h"

class IVertexArrayObject
{
public:
    virtual ~IVertexArrayObject(){};

    virtual void ReLoadVAO(std::vector<VerticiesCoords> vec) = 0;

    virtual void setMeshStructure(const MeshStructure& p_meshStructre) = 0;

    virtual void init() = 0;

    virtual GLuint getVao() = 0;
};

