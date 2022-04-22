#include "VertexArrayObjectStanderObjectFactory.h"

std::shared_ptr<IVertexArrayObject> VertexArrayObjectStanderObjectFactory::createVertexArrayObject(const MeshStructure & p_meshStructre)
{
    std::shared_ptr<IVertexArrayObject> l_vao = std::make_shared<VaoStandardObject>();
    l_vao->setMeshStructure(p_meshStructre);
    l_vao->init();
    return l_vao;
}
