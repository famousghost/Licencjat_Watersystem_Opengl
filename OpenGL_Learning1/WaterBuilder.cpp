#include "WaterBuilder.h"



WaterBuilder::WaterBuilder()
{
    height = 30;
    length = 30;
}

IMeshStructureBuilder * WaterBuilder::buildVerticiesCoords()
{
    std::vector<VerticiesCoords> vert;
    float x = -1.0f;
    float offesetX;
    float offesetY;
    float y = -1.0f;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < length; j++)
        {
            offesetX = (float)i / (float)height;
            offesetY = (float)j / (float)length;
            vert.push_back({ x + offesetX,1.0f,y + offesetY });
        }
    }
    m_meshStruct.setVerticiesCoords(vert);
    return this;
}

IMeshStructureBuilder * WaterBuilder::buildNormalCoords()
{
    std::vector<NormalCoords> normCoords;
    float x = -1.0f;
    float offesetX;
    float offesetY;
    float y = -1.0f;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < length; j++)
        {
            offesetX = (float)i / (float)height;
            offesetY = (float)j / (float)length;
            normCoords.push_back({ 0.0f,1.0f,0.0f });
        }
    }
    m_meshStruct.setNormalCoords(normCoords);
    return this;
}

IMeshStructureBuilder * WaterBuilder::buildTextureCoords()
{
    std::vector<TextCoords> tCoords;
    float x = -1.0f;
    float offesetX;
    float offesetY;
    float y = -1.0f;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < length; j++)
        {
            offesetX = (float)i / (float)height;
            offesetY = (float)j / (float)length;
            if (j % 4 == 0)
            {
                tCoords.push_back({ 0.0f,0.0f });
                tCoords.push_back({ 1.0f,0.0f });
                tCoords.push_back({ 1.0f,1.0f });
                tCoords.push_back({ 0.0f,1.0f });
            }
        }
    }
    m_meshStruct.setTextureCoords(tCoords);
    return this;
}

IMeshStructureBuilder * WaterBuilder::buildIndicies()
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

MeshStructure WaterBuilder::build() const
{
    return m_meshStruct;
}