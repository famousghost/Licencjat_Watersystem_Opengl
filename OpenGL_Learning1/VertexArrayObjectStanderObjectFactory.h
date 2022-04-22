#pragma once
#include "VertexArrayObjectFactory.h"

class VertexArrayObjectStanderObjectFactory : public VertexArrayObjectFactory
{
public:
    std::shared_ptr<IVertexArrayObject> createVertexArrayObject(const MeshStructure & p_meshStructre) override;
};

