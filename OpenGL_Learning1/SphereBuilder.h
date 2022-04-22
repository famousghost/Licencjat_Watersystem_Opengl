#pragma once
#include "IMeshStructureBuilder.h"

class SphereBuilder : public IMeshStructureBuilder
{
public:
	SphereBuilder();
    IMeshStructureBuilder* buildVerticiesCoords() override;
    IMeshStructureBuilder* buildNormalCoords() override;
    IMeshStructureBuilder* buildTextureCoords() override;
    IMeshStructureBuilder* buildIndicies() override;

    MeshStructure build() const;
private:
    MeshStructure m_meshStruct;
    int stacks;
    int slices;
};

