#include "MeshStructure.h"

void MeshStructure::setVerticiesCoords(const std::vector<VerticiesCoords>& p_verticiesCoords)
{
    m_verticiesCoords = p_verticiesCoords;
}

void MeshStructure::setNormalCoords(const std::vector<NormalCoords>& p_normalsCoords)
{
    m_normalsCoords = p_normalsCoords;
}

void MeshStructure::setTextureCoords(const std::vector<TextCoords>& p_textureCoords)
{
    m_textureCoords = p_textureCoords;
}

void MeshStructure::setIndicies(const std::vector<unsigned int>& p_indicies)
{
    m_indicies = p_indicies;
}

std::vector<VerticiesCoords> MeshStructure::getVerticiesCoords() const
{
    return m_verticiesCoords;
}

std::vector<NormalCoords> MeshStructure::getNormalsCoords() const
{
    return m_normalsCoords;
}

std::vector<TextCoords> MeshStructure::getTextureCoords() const
{
    return m_textureCoords;
}

std::vector<unsigned int> MeshStructure::getIndicies() const
{
    return m_indicies;
}
