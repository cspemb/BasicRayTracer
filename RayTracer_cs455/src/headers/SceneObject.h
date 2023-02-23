#pragma once
#include <memory>

#include "Ray.h"

struct SceneObject
{
    virtual ~SceneObject() = default;
    virtual bool intersect(std::shared_ptr<Ray> r) = 0;
    
};
