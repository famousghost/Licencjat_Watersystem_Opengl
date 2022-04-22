#pragma once
#include "IMeshStructureBuilder.h"

class WaterBuilder : public IMeshStructureBuilder
{
public:
	WaterBuilder();
    IMeshStructureBuilder* buildVerticiesCoords() override;
    IMeshStructureBuilder* buildNormalCoords() override;
    IMeshStructureBuilder* buildTextureCoords() override;
    IMeshStructureBuilder* buildIndicies() override;

    MeshStructure build() const;
private:
    MeshStructure m_meshStruct;
    int height;
    int length;
};

