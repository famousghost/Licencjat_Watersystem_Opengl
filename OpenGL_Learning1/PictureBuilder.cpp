#include "PictureBuilder.h"

IMeshStructureBuilder * PictureBuilder::buildVerticiesCoords()
{
    std::vector<VerticiesCoords> vert =
    {
        VerticiesCoords{ -1.0f, 1.0f, 0.0f },
        VerticiesCoords{ 1.0f, 1.0f, 0.0f },
        VerticiesCoords{ 1.0f, -1.0f, 0.0f },
        VerticiesCoords{ 1.0f, -1.0f, 0.0f },
        VerticiesCoords{ -1.0f, -1.0f, 0.0f },
        VerticiesCoords{ -1.0f, 1.0f, 0.0f }
    };

    m_meshStruct.setVerticiesCoords(vert);
    return this;
}

IMeshStructureBuilder * PictureBuilder::buildNormalCoords()
{
    return this;
}

IMeshStructureBuilder * PictureBuilder::buildTextureCoords()
{
    std::vector<TextCoords> textCor =
    {
        TextCoords{ 0.0f, 0.0f },
        TextCoords{ 1.0f, 0.0f },
        TextCoords{ 1.0f, 1.0f },
        TextCoords{ 1.0f, 1.0f },
        TextCoords{ 0.0f, 1.0f },
        TextCoords{ 0.0f, 0.0f }
    };
    m_meshStruct.setTextureCoords(textCor);

    return this;
}

IMeshStructureBuilder * PictureBuilder::buildIndicies()
{
    return this;
}

MeshStructure PictureBuilder::build() const
{
    return m_meshStruct;
}