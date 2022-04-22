#include "VaoStandardObject.h"


VaoStandardObject::~VaoStandardObject()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &VBO2);
    glDeleteBuffers(1, &VBO3);
    glDeleteBuffers(1, &EBO);
}

void VaoStandardObject::ReLoadVAO(std::vector<VerticiesCoords> vec)
{
    m_meshStructure.setVerticiesCoords(vec);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    //glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * (*verticies).size(), &(*verticies)[0], GL_STATIC_DRAW);
    glBufferDataV(GL_ARRAY_BUFFER, m_meshStructure.getVerticiesCoords(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    glBufferDataV(GL_ELEMENT_ARRAY_BUFFER, m_meshStructure.getIndicies(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VerticiesCoords), (GLvoid*)0);

    glBindBuffer(GL_ARRAY_BUFFER, VBO2);

    glBufferDataV(GL_ARRAY_BUFFER, m_meshStructure.getTextureCoords(), GL_STATIC_DRAW);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(TextCoords), (GLvoid*)0);

    glBindBuffer(GL_ARRAY_BUFFER, VBO3);

    glBufferDataV(GL_ARRAY_BUFFER, m_meshStructure.getNormalsCoords(), GL_STATIC_DRAW);

    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(NormalCoords), (GLvoid*)0);


    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}

void VaoStandardObject::setMeshStructure(const MeshStructure & p_meshStructre)
{
    m_meshStructure = p_meshStructre;
}

void VaoStandardObject::init()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &VBO2);
    glGenBuffers(1, &VBO3);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    //glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * (*verticies).size(), &(*verticies)[0], GL_STATIC_DRAW);
    glBufferDataV(GL_ARRAY_BUFFER, m_meshStructure.getVerticiesCoords(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    glBufferDataV(GL_ELEMENT_ARRAY_BUFFER, m_meshStructure.getIndicies(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VerticiesCoords), (GLvoid*)0);

    glBindBuffer(GL_ARRAY_BUFFER, VBO2);

    glBufferDataV(GL_ARRAY_BUFFER, m_meshStructure.getTextureCoords(), GL_STATIC_DRAW);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(TextCoords), (GLvoid*)0);

    glBindBuffer(GL_ARRAY_BUFFER, VBO3);

    glBufferDataV(GL_ARRAY_BUFFER, m_meshStructure.getNormalsCoords(), GL_STATIC_DRAW);

    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(NormalCoords), (GLvoid*)0);


    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}

GLuint VaoStandardObject::getVao()
{
    return VAO;
}
