#pragma once
#include "defines.h"
#include "MeshStructure.h"
#include <vector>
#include <matrix_transform.hpp>
#include <type_ptr.hpp>

class IMeshStructureBuilder
{
public:
    virtual IMeshStructureBuilder* buildVerticiesCoords() = 0;
    virtual IMeshStructureBuilder* buildNormalCoords() = 0;
    virtual IMeshStructureBuilder* buildTextureCoords() = 0;
    virtual IMeshStructureBuilder* buildIndicies() = 0;
    virtual MeshStructure build() const = 0;
};

