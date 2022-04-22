#pragma once
#include "IVertexArrayObject.h"

class VaoForWater : public IVertexArrayObject
{
public:
    VaoForWater() = default;
    ~VaoForWater();
    void ReLoadVAO(std::vector<VerticiesCoords> vec) override;

    void setMeshStructure(const MeshStructure& p_meshStructre) override;

    void init() override;

    GLuint getVao() override;

private:
    template<typename T>
    void glBufferDataV(GLenum target, const std::vector<T> & buffer, GLenum type)
    {
        glBufferData(target, sizeof(T)*buffer.size(), &buffer[0], type);
    }

    GLuint VAO;

    GLuint VBO;

    GLuint VBO2;

    GLuint EBO;

    MeshStructure m_meshStructure;
};

