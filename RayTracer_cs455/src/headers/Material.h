#pragma once
#include <memory>
#include "Ray.h"

class Scene;

class Material
{
public:
    virtual ~Material() = default;
    virtual glm::vec3 getColor(const Scene& scene, glm::vec3 normal, std::shared_ptr<Ray> r) = 0;
};
