#include "PyramidBuilder.h"

IMeshStructureBuilder * PyramidBuilder::buildVerticiesCoords()
{
    std::vector<VerticiesCoords> vert =
    {
        VerticiesCoords{ -0.5f, -0.5f, -0.5f },
        VerticiesCoords{ 0.5f, -0.5f, -0.5f },
        VerticiesCoords{ 0.0f, 0.5f, 0.0f },
        VerticiesCoords{ 0.0f, 0.5f, 0.0f },
        VerticiesCoords{ 0.0f, 0.5f, 0.0f },
        VerticiesCoords{ -0.5f, -0.5f, -0.5f },

        VerticiesCoords{ -0.5f, -0.5f, 0.5f },
        VerticiesCoords{ 0.5f, -0.5f, 0.5f },
        VerticiesCoords{ 0.0f, 0.5f, 0.0f },
        VerticiesCoords{ 0.0f, 0.5f, 0.0f },
        VerticiesCoords{ 0.0f, 0.5f, 0.0f },
        VerticiesCoords{ -0.5f, -0.5f, 0.5f },

        VerticiesCoords{ 0.0f, 0.5f, 0.0f },
        VerticiesCoords{ 0.0f, 0.5f, 0.0f },
        VerticiesCoords{ -0.5f, -0.5f, -0.5f },
        VerticiesCoords{ -0.5f, -0.5f, -0.5f },
        VerticiesCoords{ -0.5f, -0.5f, 0.5f },
        VerticiesCoords{ 0.0f, 0.5f, 0.0f },

        VerticiesCoords{ 0.0f, 0.5f, 0.0f },
        VerticiesCoords{ 0.0f, 0.5f, 0.0f },
        VerticiesCoords{ 0.5f, -0.5f, -0.5f },
        VerticiesCoords{ 0.5f, -0.5f, -0.5f },
        VerticiesCoords{ 0.5f, -0.5f, 0.5f },
        VerticiesCoords{ 0.0f, 0.5f, 0.0f },

        VerticiesCoords{ -0.5f, -0.5f, -0.5f },
        VerticiesCoords{ 0.5f, -0.5f, -0.5f },
        VerticiesCoords{ 0.5f, -0.5f, 0.5f },
        VerticiesCoords{ 0.5f, -0.5f, 0.5f },
        VerticiesCoords{ -0.5f, -0.5f, 0.5f },
        VerticiesCoords{ -0.5f, -0.5f, -0.5f },

        VerticiesCoords{ 0.0f, 0.5f, 0.0f },
        VerticiesCoords{ 0.0f, 0.5f, 0.0f },
        VerticiesCoords{ 0.0f, 0.5f, 0.0f },
        VerticiesCoords{ 0.0f, 0.5f, 0.0f },
        VerticiesCoords{ 0.0f, 0.5f, 0.0f },
        VerticiesCoords{ 0.f, 0.5f, 0.0f }
    };
    m_meshStruct.setVerticiesCoords(vert);
    return this;
}

IMeshStructureBuilder * PyramidBuilder::buildNormalCoords()
{
    std::vector<NormalCoords> normCoords =
    {
        NormalCoords{ 0.0f,  0.0f, -1.0f },
        NormalCoords{ 0.0f,  0.0f, -1.0f },
        NormalCoords{ 0.0f,  0.0f, -1.0f },
        NormalCoords{ 0.0f,  0.0f, -1.0f },
        NormalCoords{ 0.0f,  0.0f, -1.0f },
        NormalCoords{ 0.0f,  0.0f, -1.0f },

        NormalCoords{ 0.0f,  0.0f, 1.0f },
        NormalCoords{ 0.0f,  0.0f, 1.0f },
        NormalCoords{ 0.0f,  0.0f, 1.0f },
        NormalCoords{ 0.0f,  0.0f, 1.0f },
        NormalCoords{ 0.0f,  0.0f, 1.0f },
        NormalCoords{ 0.0f,  0.0f, 1.0f },

        NormalCoords{ -1.0f,  0.0f, 0.0f },
        NormalCoords{ -1.0f,  0.0f, 0.0f },
        NormalCoords{ -1.0f,  0.0f, 0.0f },
        NormalCoords{ -1.0f,  0.0f, 0.0f },
        NormalCoords{ -1.0f,  0.0f, 0.0f },
        NormalCoords{ -1.0f,  0.0f, 0.0f },

        NormalCoords{ 1.0f,  0.0f, 0.0f },
        NormalCoords{ 1.0f,  0.0f, 0.0f },
        NormalCoords{ 1.0f,  0.0f, 0.0f },
        NormalCoords{ 1.0f,  0.0f, 0.0f },
        NormalCoords{ 1.0f,  0.0f, 0.0f },
        NormalCoords{ 1.0f,  0.0f, 0.0f },

        NormalCoords{ 0.0f,  -1.0f, 0.0f },
        NormalCoords{ 0.0f,  -1.0f, 0.0f },
        NormalCoords{ 0.0f,  -1.0f, 0.0f },
        NormalCoords{ 0.0f,  -1.0f, 0.0f },
        NormalCoords{ 0.0f,  -1.0f, 0.0f },
        NormalCoords{ 0.0f,  -1.0f, 0.0f },

        NormalCoords{ 0.0f,  1.0f, 0.0f },
        NormalCoords{ 0.0f,  1.0f, 0.0f },
        NormalCoords{ 0.0f,  1.0f, 0.0f },
        NormalCoords{ 0.0f,  1.0f, 0.0f },
        NormalCoords{ 0.0f,  1.0f, 0.0f },
        NormalCoords{ 0.0f,  1.0f, 0.0f },
    };
    m_meshStruct.setNormalCoords(normCoords);
    return this;
}

IMeshStructureBuilder * PyramidBuilder::buildTextureCoords()
{
    std::vector<TextCoords> textCor =
    {
        TextCoords{ 0.0f, 0.0f },
        TextCoords{ 1.0f, 0.0f },
        TextCoords{ 1.0f, 1.0f },
        TextCoords{ 1.0f, 1.0f },
        TextCoords{ 0.0f, 1.0f },
        TextCoords{ 0.0f, 0.0f },

        TextCoords{ 0.0f, 0.0f },
        TextCoords{ 1.0f, 0.0f },
        TextCoords{ 1.0f, 1.0f },
        TextCoords{ 1.0f, 1.0f },
        TextCoords{ 0.0f, 1.0f },
        TextCoords{ 0.0f, 0.0f },

        TextCoords{ 1.0f, 0.0f },
        TextCoords{ 1.0f, 1.0f },
        TextCoords{ 0.0f, 1.0f },
        TextCoords{ 0.0f, 1.0f },
        TextCoords{ 0.0f, 0.0f },
        TextCoords{ 1.0f, 0.0f },

        TextCoords{ 1.0f, 0.0f },
        TextCoords{ 1.0f, 1.0f },
        TextCoords{ 0.0f, 1.0f },
        TextCoords{ 0.0f, 1.0f },
        TextCoords{ 0.0f, 0.0f },
        TextCoords{ 1.0f, 0.0f },

        TextCoords{ 0.0f, 1.0f },
        TextCoords{ 1.0f, 1.0f },
        TextCoords{ 1.0f, 0.0f },
        TextCoords{ 1.0f, 0.0f },
        TextCoords{ 0.0f, 0.0f },
        TextCoords{ 0.0f, 1.0f },

        TextCoords{ 0.0f, 1.0f },
        TextCoords{ 1.0f, 1.0f },
        TextCoords{ 1.0f, 0.0f },
        TextCoords{ 1.0f, 0.0f },
        TextCoords{ 0.0f, 0.0f },
        TextCoords{ 0.0f, 1.0f }
    };
    m_meshStruct.setTextureCoords(textCor);
    return this;
}

IMeshStructureBuilder * PyramidBuilder::buildIndicies()
{
    std::vector<GLuint> indi
    {
        0,1,2,
        0,3,2,
        5,1,2,
        5,6,2,
        6,7,4,
        6,5,4,
        7,3,0,
        7,4,0,
        4,5,1,
        4,0,1,
        7,3,2,
        7,6,2
    };
    m_meshStruct.setIndicies(indi);
    return this;
}

MeshStructure PyramidBuilder::build() const
{
    return m_meshStruct;
}