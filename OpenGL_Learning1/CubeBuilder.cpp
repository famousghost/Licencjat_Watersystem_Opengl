#include "CubeBuilder.h"

IMeshStructureBuilder * CubeBuilder::buildVerticiesCoords()
{
    std::vector<VerticiesCoords> vert =
    {
        VerticiesCoords{ -0.5f, -0.5f, -0.5f },
        VerticiesCoords{ 0.5f, -0.5f, -0.5f },
        VerticiesCoords{ 0.5f, 0.5f, -0.5f },
        VerticiesCoords{ 0.5f, 0.5f, -0.5f },
        VerticiesCoords{ -0.5f, 0.5f, -0.5f },
        VerticiesCoords{ -0.5f, -0.5f, -0.5f },

        VerticiesCoords{ -0.5f, -0.5f, 0.5f },
        VerticiesCoords{ 0.5f, -0.5f, 0.5f },
        VerticiesCoords{ 0.5f, 0.5f, 0.5f },
        VerticiesCoords{ 0.5f, 0.5f, 0.5f },
        VerticiesCoords{ -0.5f, 0.5f, 0.5f },
        VerticiesCoords{ -0.5f, -0.5f, 0.5f },

        VerticiesCoords{ -0.5f, 0.5f, 0.5f },
        VerticiesCoords{ -0.5f, 0.5f, -0.5f },
        VerticiesCoords{ -0.5f, -0.5f, -0.5f },
        VerticiesCoords{ -0.5f, -0.5f, -0.5f },
        VerticiesCoords{ -0.5f, -0.5f, 0.5f },
        VerticiesCoords{ -0.5f, 0.5f, 0.5f },

        VerticiesCoords{ 0.5f, 0.5f, 0.5f },
        VerticiesCoords{ 0.5f, 0.5f, -0.5f },
        VerticiesCoords{ 0.5f, -0.5f, -0.5f },
        VerticiesCoords{ 0.5f, -0.5f, -0.5f },
        VerticiesCoords{ 0.5f, -0.5f, 0.5f },
        VerticiesCoords{ 0.5f, 0.5f, 0.5f },

        VerticiesCoords{ -0.5f, -0.5f, -0.5f },
        VerticiesCoords{ 0.5f, -0.5f, -0.5f },
        VerticiesCoords{ 0.5f, -0.5f, 0.5f },
        VerticiesCoords{ 0.5f, -0.5f, 0.5f },
        VerticiesCoords{ -0.5f, -0.5f, 0.5f },
        VerticiesCoords{ -0.5f, -0.5f, -0.5f },

        VerticiesCoords{ -0.5f, 0.5f, -0.5f },
        VerticiesCoords{ 0.5f, 0.5f, -0.5f },
        VerticiesCoords{ 0.5f, 0.5f, 0.5f },
        VerticiesCoords{ 0.5f, 0.5f, 0.5f },
        VerticiesCoords{ -0.5f, 0.5f, 0.5f },
        VerticiesCoords{ -0.5f, 0.5f, -0.5f }
    };
    m_meshStruct.setVerticiesCoords(vert);
    return this;
}

IMeshStructureBuilder * CubeBuilder::buildNormalCoords()
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

IMeshStructureBuilder * CubeBuilder::buildTextureCoords()
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

IMeshStructureBuilder * CubeBuilder::buildIndicies()
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

MeshStructure CubeBuilder::build() const
{
    return m_meshStruct;
}