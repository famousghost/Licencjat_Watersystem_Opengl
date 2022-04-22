#pragma once
#include "defines.h"
#include <vector>

class MeshStructure
{
public:

    void setVerticiesCoords(const std::vector<VerticiesCoords>& p_verticiesCoords);
    void setNormalCoords(const std::vector<NormalCoords>& p_normalsCoords);
    void setTextureCoords(const std::vector<TextCoords>& p_textureCoords);
    void setIndicies(const std::vector<unsigned int>& p_indicies);

    std::vector<VerticiesCoords> getVerticiesCoords() const;
    std::vector<NormalCoords> getNormalsCoords() const;
    std::vector<TextCoords> getTextureCoords() const;
    std::vector<unsigned int> getIndicies() const;

private:
    std::vector<VerticiesCoords> m_verticiesCoords;
    std::vector<NormalCoords> m_normalsCoords;
    std::vector<TextCoords> m_textureCoords;
    std::vector<unsigned int> m_indicies;
};

