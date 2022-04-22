#pragma once
#include "VertexArrayObjectFactory.h"

class VertexArrayObjectWaterFactory : public VertexArrayObjectFactory
{
public:
    std::shared_ptr<IVertexArrayObject> createVertexArrayObject(const MeshStructure & p_meshStructre) override;
};

