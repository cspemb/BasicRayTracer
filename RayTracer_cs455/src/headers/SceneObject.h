#pragma once
#include <memory>
#include <glm/vec3.hpp>

#include "Ray.h"

struct SceneObject
{
    virtual ~SceneObject() = default;
    virtual float intersect(std::shared_ptr<Ray> r) = 0;
    virtual glm::vec3 getNormal(glm::vec3 point) = 0;
    
};
