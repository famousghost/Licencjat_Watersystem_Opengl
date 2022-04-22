#pragma once
#include "IMeshStructureBuilder.h"

class PyramidBuilder : public IMeshStructureBuilder
{
public:
    IMeshStructureBuilder* buildVerticiesCoords() override;
    IMeshStructureBuilder* buildNormalCoords() override;
    IMeshStructureBuilder* buildTextureCoords() override;
    IMeshStructureBuilder* buildIndicies() override;

    MeshStructure build() const;
private:
    MeshStructure m_meshStruct;

};

