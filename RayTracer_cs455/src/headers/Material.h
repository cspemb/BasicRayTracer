#pragma once
#include <memory>
#include "Ray.h"

class Scene;

class Material
{
public:
    const float reflectance{};
    
    explicit Material(float reflectance)
        : reflectance(reflectance)
    {}

    virtual ~Material() = default;
    virtual glm::vec3 getColor(const Scene& scene, glm::vec3 normal, std::shared_ptr<Ray> r, bool isInShadow) = 0;
    virtual glm::vec3 getReflectedDirection(const std::shared_ptr<Ray>& incidentRay, glm::vec3 normal) = 0;
};
