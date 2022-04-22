#include "TerrainBuilder.h"



TerrainBuilder::TerrainBuilder()
{
    height = 30;
    length = 30;
}

IMeshStructureBuilder * TerrainBuilder::buildVerticiesCoords()
{
    float x = -1.0f;
    float offesetX;
    float offesetY;
    float y = -1.0f;
    std::vector<VerticiesCoords> vert;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < length; j++)
        {
            offesetX = (float)i / (float)height;
            offesetY = (float)j / (float)length;
            vert.push_back({ x + offesetX,-2.0,y + offesetY });
        }
    }
    m_meshStruct.setVerticiesCoords(vert);
    return this;
}

IMeshStructureBuilder * TerrainBuilder::buildNormalCoords()
{
    float x = -1.0f;
    float offesetX;
    float offesetY;
    float y = -1.0f;
    std::vector<NormalCoords> normCoords;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < length; j++)
        {
            offesetX = (float)i / (float)height;
            offesetY = (float)j / (float)length;
            normCoords.push_back({ x + offesetX,1.0f,y + offesetY });
        }
    }
    m_meshStruct.setNormalCoords(normCoords);
    return this;
}

IMeshStructureBuilder * TerrainBuilder::buildTextureCoords()
{
    float x = -1.0f;
    float offesetX;
    float offesetY;
    float y = -1.0f;
    std::vector<TextCoords> tCoords;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < length; j++)
        {
            offesetX = (float)i / (float)height;
            offesetY = (float)j / (float)length;
            tCoords.push_back({ x + offesetX,y + offesetY });
        }
    }
    m_meshStruct.setTextureCoords(tCoords);
    return this;
}

IMeshStructureBuilder * TerrainBuilder::buildIndicies()
{
    std::vector<GLuint> indi;

    for (int i = 0; i < height * length; ++i)
    {
        if ((i + 1) % length != 0 && (i + length)<((height*length) - 1))
        {
            indi.push_back(i);
            indi.push_back(i + length);
            indi.push_back(i + 1);

            indi.push_back(i + 1);
            indi.push_back(i + length);
            indi.push_back(i + length + 1);
        }
    }
    m_meshStruct.setIndicies(indi);
    return this;
}

MeshStructure TerrainBuilder::build() const
{
    return m_meshStruct;
}