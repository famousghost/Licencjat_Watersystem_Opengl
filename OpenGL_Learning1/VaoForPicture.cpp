#include "VaoForPicture.h"

VaoForPicture::~VaoForPicture()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &VBO2);
}

void VaoForPicture::ReLoadVAO(std::vector<VerticiesCoords> vec)
{
    m_meshStructure.setVerticiesCoords(vec);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferDataV(GL_ARRAY_BUFFER, m_meshStructure.getVerticiesCoords(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VerticiesCoords), (GLvoid*)0);

    glBindBuffer(GL_ARRAY_BUFFER, VBO2);

    glBufferDataV(GL_ARRAY_BUFFER, m_meshStructure.getTextureCoords(), GL_STATIC_DRAW);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(TextCoords), (GLvoid*)0);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}

void VaoForPicture::setMeshStructure(const MeshStructure & p_meshStructre)
{
    m_meshStructure = p_meshStructre;
}

void VaoForPicture::init()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &VBO2);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    //glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * (*verticies).size(), &(*verticies)[0], GL_STATIC_DRAW);
    glBufferDataV(GL_ARRAY_BUFFER, m_meshStructure.getVerticiesCoords(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VerticiesCoords), (GLvoid*)0);

    glBindBuffer(GL_ARRAY_BUFFER, VBO2);

    glBufferDataV(GL_ARRAY_BUFFER, m_meshStructure.getTextureCoords(), GL_STATIC_DRAW);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(TextCoords), (GLvoid*)0);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}

GLuint VaoForPicture::getVao()
{
    return VAO;
}
