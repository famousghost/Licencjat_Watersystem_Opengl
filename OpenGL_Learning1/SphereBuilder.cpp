#include "SphereBuilder.h"

SphereBuilder::SphereBuilder()
{
    stacks = 30;
    slices = 30;
}

IMeshStructureBuilder * SphereBuilder::buildVerticiesCoords()
{
    std::vector<VerticiesCoords> vert;
    float radius = 0.8f;
    for (int i = 0; i <= stacks; i++)
    {
        float V = i / (float)stacks;
        float phi = V * glm::pi<float>();
        for (int j = 0; j <= slices; j++)
        {
            float U = j / (float)slices;
            float theta = U*(glm::pi<float>() * 2);
            float x = cosf(theta) * sinf(phi);
            float y = cosf(phi);
            float z = sinf(theta) * sinf(phi);
            vert.push_back({ x * radius,y * radius,z * radius });
        }
    }
    m_meshStruct.setVerticiesCoords(vert);
    return this;
}

IMeshStructureBuilder * SphereBuilder::buildNormalCoords()
{
    std::vector<NormalCoords> normCoords;
    float radius = 0.8f;
    for (int i = 0; i <= stacks; i++)
    {
        float V = i / (float)stacks;
        float phi = V * glm::pi<float>();
        for (int j = 0; j <= slices; j++)
        {
            float U = j / (float)slices;
            float theta = U*(glm::pi<float>() * 2);
            float x = cosf(theta) * sinf(phi);
            float y = cosf(phi);
            float z = sinf(theta) * sinf(phi);
            normCoords.push_back({ x * radius,y * radius,z * radius });
        }
    }
    m_meshStruct.setNormalCoords(normCoords);
    return this;
}

IMeshStructureBuilder * SphereBuilder::buildTextureCoords()
{
    std::vector<TextCoords> tCoords;    
    
    float radius = 0.8f;
    for (int i = 0; i <= stacks; i++)
    {
        float V = i / (float)stacks;
        float phi = V * glm::pi<float>();
        for (int j = 0; j <= slices; j++)
        {
            float U = j / (float)slices;
            float theta = U*(glm::pi<float>() * 2);
            float x = cosf(theta) * sinf(phi);
            float y = cosf(phi);
            float z = sinf(theta) * sinf(phi);
            tCoords.push_back({ x * radius,y * radius });
        }
    }
    m_meshStruct.setTextureCoords(tCoords);
    return this;
}

IMeshStructureBuilder * SphereBuilder::buildIndicies()
{
    std::vector<GLuint> indi;
    for (int i = 0; i < slices * stacks + slices; ++i) {

        indi.push_back(i);
        indi.push_back(i + slices + 1);
        indi.push_back(i + slices);

        indi.push_back(i + slices + 1);
        indi.push_back(i);
        indi.push_back(i + 1);
    }
    m_meshStruct.setIndicies(indi);
    return this;
}

MeshStructure SphereBuilder::build() const
{
    return m_meshStruct;
}