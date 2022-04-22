#pragma once
#include "IVertexArrayObject.h"
#include "VaoStandardObject.h"
#include "VaoForWater.h"
#include "VaoForPicture.h"
#include <memory>

class VertexArrayObjectFactory
{
public:
    virtual std::shared_ptr<IVertexArrayObject> createVertexArrayObject(const MeshStructure & p_meshStructre) = 0;
};

