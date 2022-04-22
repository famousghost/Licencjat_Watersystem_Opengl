#pragma once
#include "IMeshStructureBuilder.h"

class TerrainBuilder :public IMeshStructureBuilder
{
public:
	TerrainBuilder();
    IMeshStructureBuilder* buildVerticiesCoords() override;
    IMeshStructureBuilder* buildNormalCoords() override;
    IMeshStructureBuilder* buildTextureCoords() override;
    IMeshStructureBuilder* buildIndicies() override;

    MeshStructure build() const;
private:
    MeshStructure m_meshStruct;
    int height = 30;
    int length = 30;
};

