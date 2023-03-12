#pragma once
#include "LambertianMaterial.h"

class ReflectiveMaterial final : public LambertianMaterial
{
public:
    ReflectiveMaterial(float coef_diffuse, float coef_specular, float coef_ambient, const glm::vec3& diffuse_color,
        const glm::vec3& specular_color, float glossiness, float reflectance)
        : LambertianMaterial(coef_diffuse, coef_specular, coef_ambient, diffuse_color, specular_color, glossiness, reflectance)
    {}

    glm::vec3 getReflectedDirection(const std::shared_ptr<Ray>& incidentRay, glm::vec3 normal) override;
};
